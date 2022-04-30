#!/bin/bash

## ================================================================================================== ##
## Loading variables from shell script
./definitions.sh;

## ================================================================================================== ##
## Define the dictionary of datatype to KDB conversion function

declare -A CtoKDBConvertor;
declare -A KDBToCConvertor;

CtoKDBConvertor["float64"]="kf";
CtoKDBConvertor["int64"]="ki";
CtoKDBConvertor["string"]="kstr";

KDBToCConvertor["float64"]="kF";
KDBToCConvertor["int64"]="kI";
KDBToCConvertor["string"]="kS";

## ================================================================================================== ##
## Create dictionary of ROS msg file names to their KDB conversion function

declare -A subNameToKDBFunc;  ## Dictionary of functions that convert C data to KDB
declare -A subNameToCFunc;  ## Dictionary of functions that convert KDB to C data

IFS=$'\n'       # make newlines the only separator
#set -f          # disable globbing

for i in `ls /home/sean/cloud/ros_ws/src/ros2kdb/msg/*.msg`; do
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
## Load in Subscriber template code to a dictionary 
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
## Create the publisher .cpp file
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
            "| grep -v "####*"

            index=$(( index+1 ));
        done
    else
    echo -e $i| grep -v "####*"
  fi
done >./src/run/publish.cpp

## ================================================================================================== ##
## Create the subscriber .cpp file
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
            "| grep -v "####*"
        done
    else
    echo -e $i| grep -v "####*"
  fi
done >./src/run/subscribe.cpp