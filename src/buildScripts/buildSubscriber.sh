#!/bin/bash

## ================================================================================================== ##
## Sourcing variables from shell script
## ================================================================================================== ##
. $2;

. $ROS2KDB_DIR/src/functions.sh config/Subscribers.csv 
. $ROS2KDB_DIR/src/functions.sh config/cKDBAccessors.csv

IFS=$'\n'       # make newlines the only separator
#set -f          # disable globbing

## ================================================================================================== ##
## Create dictionary of ROS msg file names to their KDB conversion function
## ================================================================================================== ##

declare -A subConversion;  ## Dictionary of functions that convert ROS data to KDB

for i in `ls $ROS2KDB_DIR/../$MSG_PKG/msg/*.msg`; do
  keyName=`basename ${i::-4}`
  subConversion[$keyName]="$((1+`cat $i|wc -l`))";
  index=0;
  for line in $(cat < "$i"); do
    type=`echo $line |sed 's/[ ]\+/\t/g'|cut -f 1`;
    name=`echo $line |sed 's/[ ]\+/\t/g'|cut -f 2`;
    unnumberedType=`echo  $varname | sed 's/[0-9]//g'`
    subConversion[$keyName]=${subConversion[$keyName]}","${CtoKDBConvertor[$type]}"("$unnumberedType" (msg->"$name"))";
    index=$(( index+1 ));
  done
  subConversion[$keyName]=${subConversion[$keyName]}
  done


## ================================================================================================== ##
## Load in Subscriber template code to a dictionary 
## ================================================================================================== ##

declare -a SubCodeDict;

index=1;
for i in $(cat < "$ROS2KDB_DIR/src/templates/Sub.cpp"); do
  if [[ $i == "###"* ]];
    then 
    index=$(( index+1 ));
  fi
  SubCodeDict[$index]=${SubCodeDict[index]}"\n"$i;
 done;

## ================================================================================================== ##
## Create the subscribe.cpp file
## ================================================================================================== ##

NODE_NAME=KDBSubscriber_${1}

for i in "${SubCodeDict[@]}"; do 
  if [[ $i == *"#####FORLOOP"* ]];
    then 
        for keyVal in "${!subNameToTopic[@]}";
        do
            SUBSCRIPTION_NAME=$keyVal
            MSG_FILE=${subNameToMsg[$keyVal]}
            TOPIC_NAME=`echo ${subNameToTopic[$keyVal]}| sed 's~\/~\\\/~g'`
            KDB_PARAM_LIST=${subConversion[$MSG_FILE]}
            HEADER_NAME=`echo ${MSG_FILE}| sed -r 's/([A-Z])/_\L\1/g' | sed 's/^_//'`

            echo -e $i|sed -e "
            s/SUBSCRIPTION_NAME/$SUBSCRIPTION_NAME/g
            s/MSG_FILE/$MSG_FILE/g
            s/KDB_PARAM_LIST/$KDB_PARAM_LIST/g
            s/TOPIC_NAME/$TOPIC_NAME/g
            s/HEADER_NAME/$HEADER_NAME/g
            s/NODE_NAME/$NODE_NAME/g
            s/MSG_PKG/$MSG_PKG/g
            "| grep -v "####*"
        done
    else
    echo -e $i|sed -e "
    s/KDB_HOST/$KDB_HOST/g
    s/PORT/$KDB_SUB_PORT/g
    s/NODE_NAME/$NODE_NAME/g
    s/KDB_UNAME_PWD/$KDB_UNAME_PWD/g
    "| grep -v "####*"
  fi
done >./src/run/subscribe_${1}.cpp