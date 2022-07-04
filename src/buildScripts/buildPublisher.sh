#!/bin/bash

## ================================================================================================== ##
## Sourcing variables from shell script
## ================================================================================================== ##
. $2;

IFS=$'\n'       # make newlines the only separator
#set -f          # disable globbing

## ================================================================================================== ##
## Create dictionary of ROS msg file names to their KDB conversion function
## ================================================================================================== ##

declare -A pubConversion;  ## Dictionary of functions that convert ROS data to KDB

for i in `ls $ROS2KDB_DIR/../$MSG_PKG/msg/*.msg`; do
  keyName=`basename ${i::-4}`
  pubConversion[$keyName]="";
  index=0;
  for line in $(cat < "$i"); do
    type=`echo $line |cut -f 1`;
    name=`echo $line |cut -f 2`;
    unnumberedType=`echo  $varname | sed 's/[0-9]//g'`
    pubConversion[$keyName]=${pubConversion[$keyName]}"\n    msg."$name"="${KDBToCConvertor[$type]}"(data)["$index"];";
    index=$(( index+1 ));
  done
  pubConversion[$keyName]=${pubConversion[$keyName]}
  done

## ================================================================================================== ##
## Load in Publisher template code to a dictionary 
## ================================================================================================== ##

declare -a PubCodeDict;

index=1;
for i in $(cat < "$ROS2KDB_DIR/src/templates/Pub.cpp"); do
  if [[ $i == "###"* ]];
    then 
    index=$(( index+1 ));
  fi
  PubCodeDict[$index]=${PubCodeDict[index]}"\n"$i;
 done;

## ================================================================================================== ##
## Create the publish.cpp file
## ================================================================================================== ##

NODE_NAME=KDBPublisher_${1}

for i in "${PubCodeDict[@]}"; do 
  if [[ $i == *"#####FORLOOP"* ]];
    then 
        index=0
        for keyVal in "${!subNameToTopic[@]}";
        do
            PUBLISHER_NAME=$keyVal
            MSG_FILE=${subNameToMsg[$keyVal]}
            TOPIC_NAME=${subNameToTopic[$keyVal]}
            KDB_PARAM_LIST=${pubConversion[$MSG_FILE]}
            HEADER_NAME=`echo ${MSG_FILE}| sed -r 's/([A-Z])/_\L\1/g' | sed 's/^_//'`

            echo -e $i|sed -e "
            s/PUBLISHER_NAME/$PUBLISHER_NAME/g
            s/MSG_FILE/$MSG_FILE/g
            s/KDB_PARAM_LIST/$KDB_PARAM_LIST/g
            s/TOPIC_NAME/$TOPIC_NAME/g
            s/HEADER_NAME/$HEADER_NAME/g
            s/NODE_NAME/$NODE_NAME/g
            s/INDEX/$index/g
            s/MSG_PKG/$MSG_PKG/g
            "| grep -v "####*"

            index=$(( index+1 ));
        done
    else
    echo -e $i|sed -e "
    s/KDB_HOST/$KDB_HOST/g
    s/PORT/$KDB_PUB_PORT/g
    s/NODE_NAME/$NODE_NAME/g
    s/KDB_UNAME_PWD/$KDB_UNAME_PWD/g
    "| grep -v "####*"
  fi
done >./src/run/publish_${1}.cpp
