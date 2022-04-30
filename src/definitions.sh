#!/bin/bash

## ================================================================================================== ##
## SETTING ENV VARS
## ================================================================================================== ##

KDB_SUB_PORT=1234;
KDB_PUB_PORT=2345;
KDB_SRV_PORT=3456;
KDB_CLNT_PORT=4567;

MSG_PKG="podracer_interfaces";
SRV_PKG="podracer_interfaces";

## ================================================================================================== ##
## FILLING ARRAYS
## ================================================================================================== ##
# Subscription names are used as the key for all values. 
# These are:
# * The topic's name
# * The name of the message file
# * The header file for a given message file in C++ (TODO: Remove need for this variable and create in bash)


## Topic names for given subscription name

declare -A subNameToTopic;
#subNameToTopic["l_act_ex"]="\/l_pod\/actuate\/exhaust";
subNameToTopic["r_act_ex"]="\/r_pod\/actuate\/exhaust";
subNameToTopic["l_act_edf"]="\/l_pod\/actuate\/edf";
#subNameToTopic["r_act_edf"]="\/r_pod\/actuate\/edf";
#subNameToTopic["c_act_elev"]="\/c_pod\/actuate\/elevon";
#subNameToTopic["l_act_elev"]="\/l_pod\/actuate\/elevon";
#subNameToTopic["r_act_elev"]="\/r_pod\/actuate\/elevon";


## Message file names for a given subscription name

declare -A subNameToMsg;
#subNameToMsg["l_act_ex"]="ExhaustInput";
subNameToMsg["r_act_ex"]="ExhaustInput";
subNameToMsg["l_act_edf"]="EdfInput";
#subNameToMsg["r_act_edf"]="EdfInput";
#subNameToMsg["c_act_elev"]="ElevonInput";
#subNameToMsg["l_act_elev"]="ElevonInput";
#subNameToMsg["r_act_elev"]="ElevonInput";


## Message file name in C++ header

declare -A subNameToHeaderName;
#subNameToHeaderName["l_act_ex"]="exhaust_input";
subNameToHeaderName["r_act_ex"]="exhaust_input";
subNameToHeaderName["l_act_edf"]="edf_input";
#subNameToHeaderName["r_act_edf"]="edf_input";
#subNameToHeaderName["c_act_elev"]="elevon_input";
#subNameToHeaderName["l_act_elev"]="elevon_input";
#subNameToHeaderName["r_act_elev"]="elevon_input";
## ================================================================================================== ##
# Service names 
## ================================================================================================== ##

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
