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

declare -A subConversion;  ## Dictionary of functions that convert ROS data to KDB

for i in `ls /home/sean/cloud/ros_ws/src/racer_interfaces/msg/*.msg`; do
  keyName=`basename ${i::-4}`
  subConversion[$keyName]="$((1+`cat $i|wc -l`))";
  index=0;
  for line in $(cat < "$i"); do
    type=`echo $line |cut -f 1`;
    name=`echo $line |cut -f 2`;
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
for i in $(cat < "src/templates/Sub.cpp"); do
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
            TOPIC_NAME=${subNameToTopic[$keyVal]}
            KDB_PARAM_LIST=${subConversion[$MSG_FILE]}
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
    s/KDBSubscriber/$NODE_NAME/g
    s/KDB_UNAME_PWD/$KDB_UNAME_PWD/g
    "| grep -v "####*"
  fi
done >./src/run/subscribe_${1}.cpp