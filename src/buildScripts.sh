#!/bin/bash

## ================================================================================================== ##
## Sourcing variables from shell script
## ================================================================================================== ##
. ./src/definitions.sh;

## ==================================================================================================================================================================================================== ##
## ==================================================================================================================================================================================================== ##

IFS=$'\n'       # make newlines the only separator
#set -f          # disable globbing

## ================================================================================================== ##
## Create dictionary of ROS msg file names to their KDB conversion function
## ================================================================================================== ##

declare -A subNameToKDBFunc;  ## Dictionary of functions that convert C data to KDB
declare -A subNameToCFunc;  ## Dictionary of functions that convert KDB to C data

for i in `ls /home/sean/cloud/ros_ws/src/racer_interfaces/msg/*.msg`; do
  keyName=`basename ${i::-4}`
  subNameToKDBFunc[$keyName]="$((1+`cat $i|wc -l`))";
  subNameToCFunc[$keyName]="";
  index=0;
  for line in $(cat < "$i"); do
    type=`echo $line |cut -f 1`;
    name=`echo $line |cut -f 2`;
    unnumberedType=`echo  $varname | sed 's/[0-9]//g'`
    subNameToKDBFunc[$keyName]=${subNameToKDBFunc[$keyName]}","${CtoKDBConvertor[$type]}"("$unnumberedType" (msg->"$name"))";
    subNameToCFunc[$keyName]=${subNameToCFunc[$keyName]}"\n    msg."$name"="${KDBToCConvertor[$type]}"(data)["$index"];";
    index=$(( index+1 ));
  done
  subNameToKDBFunc[$keyName]=${subNameToKDBFunc[$keyName]}
  subNameToCFunc[$keyName]=${subNameToCFunc[$keyName]}
  done

## ================================================================================================== ##
## Create dictionary of ROS srv file names to their KDB conversion function
## ================================================================================================== ##
### FUCK need to redo loads of stuff here. 

##First, parse the service files for their request fields and response fields

## Then, make client and server convertors of each of these.

## So I need 4 dictionaries. ServerResponse, ServerRequest, ClientResponse, ClientRequest?

declare -A svcNameToKDBFunc;  ## Dictionary of functions that convert C data to KDB
declare -A svcNameToCFunc;  ## Dictionary of functions that convert KDB to C data

declare -A serverRequest;  ## Dictionary of functions that convert C data to KDB
declare -A serverResponse;  ## Dictionary of functions that convert KDB to C data


for i in `ls /home/sean/cloud/ros_ws/src/racer_interfaces/srv/*.srv`; do
  keyName=`basename ${i::-4}`
  serverRequest[$keyName]="";
  serverResponse[$keyName]="";
  clientRequest[$keyName]="";
  clientResponse[$keyName]="";

  index=0;
  fieldType="request";
  for line in $(cat < "$i"); do
    echo $line;
    if [[ $line == *"---"* ]];
        then 
        fieldType="response";
        index=0;
        continue;
    fi
    echo $keyName;
    type=`echo $line |cut -f 1`;
    echo $type;
    name=`echo $line |cut -f 2`;
    unnumberedType=`echo  $varname | sed 's/[0-9]//g'`
    echo $name;
    echo $fieldType;
    if [[ $fieldType == "request"* ]];
      then 
      serverRequest[$keyName]=${serverRequest[$keyName]}","${CtoKDBConvertor[$type]}"((request->"$name"))";

      clientRequest[$keyName]=${clientRequest[$keyName]}"\n      request->"$name" = "${KDBToCConvertor[$type]}"(data)["${index}"];";
      
      else
      
      serverResponse[$keyName]=${serverResponse[$keyName]}"\n    response->"$name"=(resp->"${KDBToCAccessor[$type]}")";
      clientResponse[$keyName]=${clientResponse[$keyName]}", "${CtoKDBConvertor[$type]}"("$unnumberedType"((future.get())->"$name")";
      echo ${serverResponse[$keyName]};
    fi

    index=$(( index+1 ));
  done
  clientResponse[$keyName]=${index}${clientResponse[$keyName]}
  echo "";
  echo "";
  serverRequest[$keyName]=${serverRequest[$keyName]}
  serverResponse[$keyName]=${serverResponse[$keyName]}
  done

## ==================================================================================================================================================================================================== ##
## ==================================================================================================================================================================================================== ##

## ================================================================================================== ##
## Load in Subscriber template code to a dictionary 
## ================================================================================================== ##

declare -a SubCodeDict;

index=1;
for i in $(cat < "src/templates/Sub.cpp"); do
  if [[ $i == "###"* ]];
    then 
    index=$(( index+1 ));
  fi
  SubCodeDict[$index]=${SubCodeDict[index]}"\n"$i;
 done;

## ================================================================================================== ##
## Load in Publisher template code to a dictionary 
## ================================================================================================== ##

declare -a PubCodeDict;

index=1;
for i in $(cat < "src/templates/Pub.cpp"); do
  if [[ $i == "###"* ]];
    then 
    index=$(( index+1 ));
  fi
  PubCodeDict[$index]=${PubCodeDict[index]}"\n"$i;
 done;

## ================================================================================================== ##
## Load in Service Server template code to a dictionary 
## ================================================================================================== ##

declare -a SrvCodeDict;

index=1;
for i in $(cat < "src/templates/Srv.cpp"); do
  if [[ $i == "###"* ]];
    then 
    index=$(( index+1 ));
  fi
  SrvCodeDict[$index]=${SrvCodeDict[index]}"\n"$i;
 done;

## ================================================================================================== ##
## Load in Service Client template code to a dictionary 
## ================================================================================================== ##

declare -a ClntCodeDict;

index=1;
for i in $(cat < "src/templates/Clnt.cpp"); do
  if [[ $i == "###"* ]];
    then 
    index=$(( index+1 ));
  fi
  ClntCodeDict[$index]=${ClntCodeDict[index]}"\n"$i;
 done;

## ==================================================================================================================================================================================================== ##
## ==================================================================================================================================================================================================== ##

## ================================================================================================== ##
## Create the subscribe.cpp file
## ================================================================================================== ##

for i in "${SubCodeDict[@]}"; do 
  if [[ $i == *"#####FORLOOP"* ]];
    then 
        for keyVal in "${!subNameToTopic[@]}";
        do
            SUBSCRIPTION_NAME=$keyVal
            MSG_FILE=${subNameToMsg[$keyVal]}
            TOPIC_NAME=${subNameToTopic[$keyVal]}
            KDB_PARAM_LIST=${subNameToKDBFunc[$MSG_FILE]}
            HEADER_NAME=${subNameToHeaderName[$keyVal]}

            echo -e $i|sed -e "
            s/SUBSCRIPTION_NAME/$SUBSCRIPTION_NAME/g
            s/MSG_FILE/$MSG_FILE/g
            s/KDB_PARAM_LIST/$KDB_PARAM_LIST/g
            s/TOPIC_NAME/$TOPIC_NAME/g
            s/HEADER_NAME/$HEADER_NAME/g
            s/MSG_PKG/$MSG_PKG/g
            "| grep -v "####*"
        done
    else
    echo -e $i|sed -e "
    s/KDB_HOST/$KDB_HOST/g
    s/PORT/$KDB_SUB_PORT/g
    s/KDB_UNAME_PWD/$KDB_UNAME_PWD/g
    "| grep -v "####*"
  fi
done >./src/run/subscribe.cpp

## ================================================================================================== ##
## Create the publish.cpp file
## ================================================================================================== ##

for i in "${PubCodeDict[@]}"; do 
  if [[ $i == *"#####FORLOOP"* ]];
    then 
        index=0
        for keyVal in "${!subNameToTopic[@]}";
        do
            PUBLISHER_NAME=$keyVal
            MSG_FILE=${subNameToMsg[$keyVal]}
            TOPIC_NAME=${subNameToTopic[$keyVal]}
            KDB_PARAM_LIST=${subNameToCFunc[$MSG_FILE]}
            HEADER_NAME=${subNameToHeaderName[$keyVal]}

            echo -e $i|sed -e "
            s/PUBLISHER_NAME/$PUBLISHER_NAME/g
            s/MSG_FILE/$MSG_FILE/g
            s/KDB_PARAM_LIST/$KDB_PARAM_LIST/g
            s/TOPIC_NAME/$TOPIC_NAME/g
            s/HEADER_NAME/$HEADER_NAME/g
            s/INDEX/$index/g
            s/MSG_PKG/$MSG_PKG/g
            "| grep -v "####*"

            index=$(( index+1 ));
        done
    else
    echo -e $i|sed -e "
    s/KDB_HOST/$KDB_HOST/g
    s/PORT/$KDB_PUB_PORT/g
    s/KDB_UNAME_PWD/$KDB_UNAME_PWD/g
    "| grep -v "####*"
  fi
done >./src/run/publish.cpp


## ================================================================================================== ##
## Create the server.cpp file
## ================================================================================================== ##

for i in "${SrvCodeDict[@]}"; do 
  if [[ $i == *"#####FORLOOP"* ]];
    then 
        index=0
        for keyVal in "${!svcNameToService[@]}";
        do
            SERVER_NAME=$keyVal
            SRV_FILE=${svcNameToSRV[$keyVal]}
            TOPIC_NAME=${svcNameToService[$keyVal]}
            KDB_PARAM_LIST=${svcNameToCFunc[$MSG_FILE]}
            HEADER_NAME=${svcNameToHeaderName[$keyVal]}
            KDB_FUNC_NAME=${svcNameToKdbFunc[$keyVal]}
            KDB_REQUEST_CONVERTOR=${serverRequest[$SRV_FILE]}
            KDB_RESPONSE_CONVERTOR=${serverResponse[$SRV_FILE]}

            echo -e $i|sed -e "
            s/SERVER_NAME/$SERVER_NAME/g
            s/SRV_FILE/$SRV_FILE/g
            s/KDB_PARAM_LIST/$KDB_PARAM_LIST/g
            s/TOPIC_NAME/$TOPIC_NAME/g
            s/HEADER_NAME/$HEADER_NAME/g
            s/INDEX/$index/g
            s/SRV_PKG/$SRV_PKG/g
            s/KDB_FUNC_NAME/$KDB_FUNC_NAME/g
            s/KDB_REQUEST_CONVERTOR/$KDB_REQUEST_CONVERTOR/g
            s/KDB_RESPONSE_CONVERTOR/$KDB_RESPONSE_CONVERTOR/g
            "| grep -v "####*"

            index=$(( index+1 ));
        done
    else
    echo -e $i|sed -e "
    s/KDB_HOST/$KDB_HOST/g
    s/PORT/$KDB_SRV_PORT/g
    s/KDB_UNAME_PWD/$KDB_UNAME_PWD/g
    "| grep -v "####*"
  fi
done >./src/run/server.cpp


## ================================================================================================== ##
## Create the client.cpp file
## ================================================================================================== ##

for i in "${ClntCodeDict[@]}"; do 
  if [[ $i == *"#####FORLOOP"* ]];
    then 
        index=0
        for keyVal in "${!clntNameToService[@]}";
        do
            CLIENT_NAME=$keyVal
            SRV_FILE=${clntNameToHeaderName[$keyVal]}
            SRV_NAME=${clntNameToSRV[$keyVal]}
            TOPIC_NAME=${clntNameToService[$keyVal]}
            KDB_PARAM_LIST=${svcNameToCFunc[$MSG_FILE]}
            HEADER_NAME=${svcNameToHeaderName[$keyVal]}
            KDB_SRV_NAME=${clntNameToKdbFunc[$keyVal]}
            KDB_CLIENT_REQUEST_CONVERTOR=${clientRequest[$SRV_FILE]}
            KDB_CLIENT_RESPONSE_CONVERTOR=${clientResponse[$SRV_FILE]}

            echo -e $i|sed -e "
            s/CLIENT_NAME/$CLIENT_NAME/g
            s/SRV_FILE/$SRV_FILE/g
            s/SRV_NAME/$SRV_NAME/g
            s/KDB_PARAM_LIST/$KDB_PARAM_LIST/g
            s/TOPIC_NAME/$TOPIC_NAME/g
            s/HEADER_NAME/$HEADER_NAME/g
            s/INDEX/$index/g
            s/CLNT_PKG/$SRV_PKG/g
            s/KDB_SRV_NAME/$KDB_SRV_NAME/g            
            s/KDB_CLIENT_REQUEST_CONVERTOR/$KDB_CLIENT_REQUEST_CONVERTOR/g
            s/KDB_CLIENT_RESPONSE_CONVERTOR/$KDB_CLIENT_RESPONSE_CONVERTOR/g
            "| grep -v "####*"

            index=$(( index+1 ));
        done
    else
    echo -e $i|sed -e "
    s/KDB_HOST/$KDB_HOST/g
    s/PORT/$KDB_CLNT_PORT/g
    s/KDB_UNAME_PWD/$KDB_UNAME_PWD/g
    "| grep -v "####*"
  fi
done >./src/run/client.cpp


