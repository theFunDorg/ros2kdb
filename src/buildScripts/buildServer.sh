#!/bin/bash

## ================================================================================================== ##
## Sourcing variables from shell script
## ================================================================================================== ##
. $2;

IFS=$'\n'       # make newlines the only separator
#set -f          # disable globbing

## ================================================================================================== ##
## Create dictionary of ROS srv file names to their KDB conversion function
## ================================================================================================== ##

declare -A serverRequest;  ## Dictionary of functions that convert C data to KDB
declare -A serverResponse;  ## Dictionary of functions that convert KDB to C data

for i in `ls $ROS2KDB_DIR/../$SRV_PKG/srv/*.srv`; do
  keyName=`basename ${i::-4}`
  serverRequest[$keyName]="";
  serverResponse[$keyName]="";

  index=0;
  fieldType="request";
  for line in $(cat < "$i"); do
    if [[ $line == *"---"* ]];
        then 
        fieldType="response";
        index=0;
        continue;
    fi
    type=`echo $line |cut -f 1`;
    name=`echo $line |cut -f 2`;
    unnumberedType=`echo  $varname | sed 's/[0-9]//g'`
    if [[ $fieldType == "request"* ]];
      then 
      serverRequest[$keyName]=${serverRequest[$keyName]}","${CtoKDBConvertor[$type]}"((request->"$name"))";
      else
      serverResponse[$keyName]=${serverResponse[$keyName]}"\n    response->"$name"=(resp->"${KDBToCAccessor[$type]}")";
    fi

    index=$(( index+1 ));
  done
  serverRequest[$keyName]=${serverRequest[$keyName]}
  serverResponse[$keyName]=${serverResponse[$keyName]}
  done

## ================================================================================================== ##
## Load in Service Server template code to a dictionary 
## ================================================================================================== ##

declare -a SrvCodeDict;

index=1;
for i in $(cat < "$ROS2KDB_DIR/src/templates/Srv.cpp"); do
  if [[ $i == "###"* ]];
    then 
    index=$(( index+1 ));
  fi
  SrvCodeDict[$index]=${SrvCodeDict[index]}"\n"$i;
 done;

## ================================================================================================== ##
## Create the server.cpp file
## ================================================================================================== ##

NODE_NAME=KDBServer_${1}

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
            HEADER_NAME=`echo ${SRV_FILE}| sed -r 's/([A-Z])/_\L\1/g' | sed 's/^_//'`
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
            s/NODE_NAME/$NODE_NAME/g
            s/KDB_REQUEST_CONVERTOR/$KDB_REQUEST_CONVERTOR/g
            s/KDB_RESPONSE_CONVERTOR/$KDB_RESPONSE_CONVERTOR/g
            "| grep -v "####*"

            index=$(( index+1 ));
        done
    else
    echo -e $i|sed -e "
    s/KDB_HOST/$KDB_HOST/g
    s/PORT/$KDB_SRV_PORT/g
    s/NODE_NAME/$NODE_NAME/g
    s/KDB_UNAME_PWD/$KDB_UNAME_PWD/g
    "| grep -v "####*"
  fi
done >./src/run/server_${1}.cpp