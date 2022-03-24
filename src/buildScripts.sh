#!/bin/bash
## Define the dictionary mapping the ROS topics to be created to their ROS msg file names
declare -A subNameToTopic;
declare -A subNameToMsg;

#subNameToTopic["l_act_ex"]="\/l_pod\/actuate\/exhaust"
subNameToTopic["r_act_ex"]="\/r_pod\/actuate\/exhaust"
subNameToTopic["l_act_edf"]="\/l_pod\/actuate\/edf"
#subNameToTopic["r_act_edf"]="\/r_pod\/actuate\/edf"
#subNameToTopic["c_act_elev"]="\/c_pod\/actuate\/elevon"
#subNameToTopic["l_act_elev"]="\/l_pod\/actuate\/elevon"
#subNameToTopic["r_act_elev"]="\/r_pod\/actuate\/elevon"

#subNameToMsg["l_act_ex"]="ExhaustInput";
subNameToMsg["r_act_ex"]="ExhaustInput";
subNameToMsg["l_act_edf"]="EdfInput";
#subNameToMsg["r_act_edf"]="EdfInput";
#subNameToMsg["c_act_elev"]="ElevonInput";
#subNameToMsg["l_act_elev"]="ElevonInput";
#subNameToMsg["r_act_elev"]="ElevonInput";

#subNameToHeaderName["l_act_ex"]="exhaust_input";
subNameToHeaderName["r_act_ex"]="exhaust_input";
subNameToHeaderName["l_act_edf"]="edf_input";
#subNameToHeaderName["r_act_edf"]="edf_input";
#subNameToHeaderName["c_act_elev"]="elevon_input";
#subNameToHeaderName["l_act_elev"]="elevon_input";
#subNameToHeaderName["r_act_elev"]="elevon_input";

##["l_pod/sensor/locate"]="locate";
##["r_pod/sensor/locate"]="locate";
##["c_pod/sensor/antenna"]="antenna";
##["l_pod/sensor/exhaust"]="exhaust_output";
##["r_pod/sensor/exhaust"]="exhaust_output";
##["l_pod/sensor/edf"]="edf_output";
##["r_pod/sensor/edf"]="edf_output";
##["c_pod/sensor/elevon"]="elevon_output";
##["l_pod/sensor/elevon"]="elevon_output";
##["r_pod/sensor/elevon"]="elevon_output";
## Define the dictionary of datatype to KDB conversion function
declare -A CtoKDBConvertor;
declare -A KDBToCConvertor;

CtoKDBConvertor["float64"]="kf";
CtoKDBConvertor["string"]="kstr";
KDBToCConvertor["float64"]="f (F)";
KDBToCConvertor["string"]="s (S)";


## Create dictionary of ROS msg file names to their KDB conversion function
declare -A subNameToKDBFunc;  ## Dictionary of functions that convert C data to KDB
declare -A subNameToCFunc;  ## Dictionary of functions that convert KDB to C data

IFS=$'\n'       # make newlines the only separator
#set -f          # disable globbing

for i in `ls /home/sean/cloud/ros_ws/src/ros2kdb/msg/*.msg`; do
  keyName=`basename ${i::-4}`
  subNameToKDBFunc[$keyName]="$((1+`cat $i|wc -l`))";
  subNameToCFunc[$keyName]="";
  #echo $i
  #echo "$((1+`cat $i|wc -l`))"
  index=0;
  for line in $(cat < "$i"); do
    type=`echo $line |cut -f 1`;
    name=`echo $line |cut -f 2`;
    #echo $type;
    #echo $name;
    subNameToKDBFunc[$keyName]=${subNameToKDBFunc[$keyName]}","${CtoKDBConvertor[$type]}"("$type" (msg->"$name"))";
    subNameToCFunc[$keyName]=${subNameToCFunc[$keyName]}"\n    msg."$name"=(response["$index"])->"${KDBToCConvertor[$type]};
    index=$(( index+1 ));
    #echo ${subNameToKDBFunc[$keyName]}
    #echo ${KDBToMsgFunc[$i]}
  done
  subNameToKDBFunc[$keyName]=${subNameToKDBFunc[$keyName]}
  subNameToCFunc[$keyName]=${subNameToCFunc[$keyName]}

done
## Load in Subscriber template code to a dictionary 
declare -a SubCodeDict;

index=1;
for i in $(cat < "src/templateSub.cpp"); do
  if [[ $i == "###"* ]];
    then 
    index=$(( index+1 ));
  fi
  SubCodeDict[$index]=${SubCodeDict[index]}"\n"$i;
 done;


## Load in Publisher template code to a dictionary 
declare -a PubCodeDict;

index=1;
for i in $(cat < "src/templatePub.cpp"); do
  if [[ $i == "###"* ]];
    then 
    index=$(( index+1 ));
  fi
  PubCodeDict[$index]=${PubCodeDict[index]}"\n"$i;
 done;
 


## Create the publisher .cpp file
for i in "${PubCodeDict[@]}"; do 
  if [[ $i == *"#####FORLOOP"* ]];
    then 
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
            "| grep -v "####*"
        done
    else
    echo -e $i| grep -v "####*"
  fi
done >./src/pubTest.cpp

# Create the subscriber .cpp file
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
done >./src/subTest.cpp

# Somewhere here i have a loop, inside an if where the if checks there's FORLOOP
#for i in "${!subNameToKDBFunc[@]}"
#do
#echo "${i}=${subNameToKDBFunc[$i]}"
#done
