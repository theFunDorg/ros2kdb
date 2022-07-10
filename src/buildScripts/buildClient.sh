#!/bin/bash

## ================================================================================================== ##
## Sourcing variables from shell script
## ================================================================================================== ##
. $2;

. $ROS2KDB_DIR/src/functions.sh config/Clients.csv 
. $ROS2KDB_DIR/src/functions.sh config/cKDBAccessors.csv

IFS=$'\n'       # make newlines the only separator
#set -f          # disable globbing

## ================================================================================================== ##
## Create dictionary of ROS srv file names to their KDB conversion function
## ================================================================================================== ##

declare -A clientRequest;  ## Dictionary of functions that convert C data to KDB
declare -A clientResponse;  ## Dictionary of functions that convert KDB to C data

for i in `ls $ROS2KDB_DIR/../$SRV_PKG/srv/*.srv`; do
  keyName=`basename ${i::-4}`
  clientRequest[$keyName]="";
  clientResponse[$keyName]="";

  index=0;
  fieldType="request";
  for line in $(cat < "$i"); do
    if [[ $line == *"---"* ]];
        then 
        fieldType="response";
        index=0;
        continue;
    fi
    type=`echo $line |sed 's/ /\t/g'|cut -f 1`;
    name=`echo $line |sed 's/ /\t/g'|cut -f 2`;
    unnumberedType=`echo  $varname | sed 's/[0-9]//g'`
    if [[ $fieldType == "request"* ]];
      then 
      clientRequest[$keyName]=${clientRequest[$keyName]}"\n      request->"$name" = "${KDBToCConvertor[$type]}"(data)["${index}"];";
      else
      clientResponse[$keyName]=${clientResponse[$keyName]}", "${CtoKDBConvertor[$type]}"("$unnumberedType"((future.get())->"$name")";
    fi

    index=$(( index+1 ));
  done
  clientResponse[$keyName]=${index}${clientResponse[$keyName]}")";
  clientRequest[$keyName]=${clientRequest[$keyName]}
  done

## ================================================================================================== ##
## Load in Service Client template code to a dictionary 
## ================================================================================================== ##

declare -a ClntCodeDict;

index=1;
for i in $(cat < "$ROS2KDB_DIR/src/templates/Clnt.cpp"); do
  if [[ $i == "###"* ]];
    then 
    index=$(( index+1 ));
  fi
  ClntCodeDict[$index]=${ClntCodeDict[index]}"\n"$i;
 done;

## ================================================================================================== ##
## Create the client.cpp file
## ================================================================================================== ##

NODE_NAME=KDBClient_${1}

for i in "${ClntCodeDict[@]}"; do 
  if [[ $i == *"#####FORLOOP"* ]];
    then 
        index=0
        for keyVal in "${!clntNameToService[@]}";
        do
            CLIENT_NAME=$keyVal
            SRV_NAME=${clntNameToSRV[$keyVal]}
            TOPIC_NAME=`echo ${clntNameToService[$keyVal]}| sed 's~\/~\\\/~g'`
            KDB_PARAM_LIST=${svcNameToCFunc[$SRV_NAME]}
            HEADER_NAME=`echo ${SRV_NAME}| sed -r 's/([A-Z])/_\L\1/g' | sed 's/^_//'`
            KDB_SRV_NAME=${clntNameToKdbFunc[$keyVal]}
            KDB_CLIENT_REQUEST_CONVERTOR=${clientRequest[$SRV_NAME]}
            KDB_CLIENT_RESPONSE_CONVERTOR=${clientResponse[$SRV_NAME]}

            echo -e $i|sed -e "
            s/CLIENT_NAME/$CLIENT_NAME/g
            s/SRV_NAME/$SRV_NAME/g
            s/KDB_PARAM_LIST/$KDB_PARAM_LIST/g
            s/TOPIC_NAME/$TOPIC_NAME/g
            s/HEADER_NAME/$HEADER_NAME/g
            s/INDEX/$index/g
            s/CLNT_PKG/$SRV_PKG/g
            s/KDB_SRV_NAME/$KDB_SRV_NAME/g
            s/NODE_NAME/$NODE_NAME/g
            s/KDB_CLIENT_REQUEST_CONVERTOR/$KDB_CLIENT_REQUEST_CONVERTOR/g
            s/KDB_CLIENT_RESPONSE_CONVERTOR/$KDB_CLIENT_RESPONSE_CONVERTOR/g
            "| grep -v "####*"

            index=$(( index+1 ));
        done
    else
    echo -e $i|sed -e "
    s/KDB_HOST/$KDB_HOST/g
    s/PORT/$KDB_CLNT_PORT/g
    s/NODE_NAME/$NODE_NAME/g
    s/KDB_UNAME_PWD/$KDB_UNAME_PWD/g
    "| grep -v "####*"
  fi
done >./src/run/client_${1}.cpp