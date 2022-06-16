#!/bin/bash

## ================================================================================================== ##
## SETTING ENV VARS
## ================================================================================================== ##

KDB_SUB_PORT="1234";
KDB_PUB_PORT="2345";
KDB_SRV_PORT="3456";
KDB_CLNT_PORT="4567";
KDB_HOST="0.0.0.0";
KDB_UNAME_PWD="myusername:mypassword"

MSG_PKG="racer_interfaces";
SRV_PKG="racer_interfaces";

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
# Service names are used as the key for all values. 
# These are:
# * The topic's name
# * The name of the message file
# * The header file for a given message file in C++ (TODO: Remove need for this variable and create in bash)


## Service names for given Service

declare -A svcNameToService;
svcNameToService["r_srv_lp"]="\/r_pod\/service\/lvPosns";
svcNameToService["l_srv_es"]="\/l_pod\/service\/edfSt";
svcNameToService["l_srv_srv"]="\/l_pod\/service\/serve";

## Service file names for a given service
declare -A svcNameToSRV;
svcNameToSRV["r_srv_lp"]="levelPositions";
svcNameToSRV["l_srv_es"]="EdfState";
svcNameToSRV["l_srv_srv"]="Serve";


## Service file name in C++ header
declare -A svcNameToHeaderName;
svcNameToHeaderName["r_srv_lp"]="level_positions";
svcNameToHeaderName["l_srv_es"]="edf_state";
svcNameToHeaderName["l_srv_srv"]="serve";

# KDB function to call if necessary
declare -A svcNameToKdbFunc;
svcNameToKdbFunc["r_srv_lp"]=".ros.levelPositions";
svcNameToKdbFunc["l_srv_es"]=".ros.edfState";
svcNameToKdbFunc["l_srv_srv"]=".ros.Serve";

## ================================================================================================== ##
## Define the dictionary of datatype to KDB conversion function
## ================================================================================================== ##

declare -A CtoKDBConvertor;
declare -A KDBToCConvertor;

CtoKDBConvertor["float64"]="kf";
CtoKDBConvertor["int64"]="ki";
CtoKDBConvertor["string"]="kstr";
CtoKDBConvertor["bool"]="kb";

KDBToCConvertor["float64"]="kF";
KDBToCConvertor["int64"]="kI";
KDBToCConvertor["string"]="kS";
KDBToCConvertor["bool"]="kB";

KDBToCAccessor["float"]="f";

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
