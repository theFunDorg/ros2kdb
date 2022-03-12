#!/bin/bash
## Define the dictionary mapping the ROS topics to be created to their ROS msg file names
declare -A subNameToTopic;
declare -A subNameToMsg;

subNameToTopic["l_act_ex"]="l_pod\/actuate\/exhaust"
subNameToTopic["r_act_ex"]="r_pod\/actuate\/exhaust"
subNameToTopic["l_act_edf"]="l_pod\/actuate\/edf"
subNameToTopic["r_act_edf"]="r_pod\/actuate\/edf"
subNameToTopic["c_act_elev"]="c_pod\/actuate\/elevon"
subNameToTopic["l_act_elev"]="l_pod\/actuate\/elevon"
subNameToTopic["r_act_elev"]="r_pod\/actuate\/elevon"

subNameToMsg["l_act_ex"]="exhaust_input";
subNameToMsg["r_act_ex"]="exhaust_input";
subNameToMsg["l_act_edf"]="edf_input";
subNameToMsg["r_act_edf"]="edf_input";
subNameToMsg["c_act_elev"]="elevon_input";
subNameToMsg["l_act_elev"]="elevon_input";
subNameToMsg["r_act_elev"]="elevon_input";

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

CtoKDBConvertor["float64"]="kF";
CtoKDBConvertor["string"]="kstr";
KDBToCConvertor["float64"]="kF";
KDBToCConvertor["string"]="kstr";


## Create dictionary of ROS msg file names to their KDB conversion function
declare -A subNameToKDBFunc;  ## Dictionary of functions that convert C data to KDB
declare -A subNameToCFunc;  ## Dictionary of functions that convert KDB to C data

IFS=$'\n'       # make newlines the only separator
#set -f          # disable globbing

for i in `ls /home/sean/cloud/ros_ws/src/febkdb/msg/*.msg`; do
  keyName=`basename ${i::-4}`
  subNameToKDBFunc[$keyName]="$((1+`cat $i|wc -l`))";
  subNameToCFunc[$keyName]="";
  #echo $i
  #echo "$((1+`cat $i|wc -l`))"
  for line in $(cat < "$i"); do
    type=`echo $line |cut -f 1`;
    name=`echo $line |cut -f 2`;
    #echo $type;
    #echo $name;
    subNameToKDBFunc[$keyName]=${subNameToKDBFunc[$keyName]}","${CtoKDBConvertor[$type]}"("$name")";
    subNameToCFunc[$keyName]=${subNameToCFunc[$keyName]}","${KDBToCConvertor[$type]}"("$name")";
    #echo ${subNameToKDBFunc[$keyName]}
    #echo ${KDBToMsgFunc[$i]}
  done
  subNameToKDBFunc[$keyName]=${subNameToKDBFunc[$keyName]}
  subNameToCFunc[$keyName]=${subNameToCFunc[$keyName]:1}

done
## Load in Subscriber template code to a dictionary 
declare -a SubCodeDict;

index=1;
for i in $(cat < "src/template"); do
  if [[ $i == "###"* ]];
    then 
    index=$(( index+1 ));
  fi
  SubCodeDict[$index]=${SubCodeDict[index]}"\n"$i;
 done;


## Load in Publisher template code to a dictionary 
declare -a PubCodeDict;



## Create the publisher .cpp file


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

            echo -e $i|sed -e "
            s/SUBSCRIPTION_NAME/$SUBSCRIPTION_NAME/g
            s/MSG_FILE/$MSG_FILE/g
            s/KDB_PARAM_LIST/$KDB_PARAM_LIST/g
            s/TOPIC_NAME/$TOPIC_NAME/g
            "| grep -v "####*"
        done
    else
    echo -e $i| grep -v "####*"
    #echo hi
  fi
done;

# Somewhere here i have a loop, inside an if where the if checks there's FORLOOP
#for i in "${!subNameToKDBFunc[@]}"
#do
#echo "${i}=${subNameToKDBFunc[$i]}"
#done
