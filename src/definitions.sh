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
subNameToTopic["r_act_ex"]="\/r_pod\/actuate\/exhaust";
subNameToTopic["l_act_edf"]="\/l_pod\/actuate\/edf";


## Message file names for a given subscription name

declare -A subNameToMsg;
subNameToMsg["r_act_ex"]="ExhaustInput";
subNameToMsg["l_act_edf"]="EdfInput";


## Message file name in C++ header

declare -A subNameToHeaderName;

subNameToHeaderName["r_act_ex"]="exhaust_input";
subNameToHeaderName["l_act_edf"]="edf_input";

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
svcNameToSRV["r_srv_lp"]="LevelPositions";
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
# Client names 
## ================================================================================================== ##
# Client names are used as the key for all values. 
# These are:
# * The topic's name
# * The name of the message file
# * The header file for a given message file in C++ (TODO: Remove need for this variable and create in bash)


## Client names for given Client

declare -A clntNameToService;
clntNameToService["r_srv_lp"]="\/r_pod\/service\/lvPosns";
clntNameToService["l_srv_es"]="\/l_pod\/service\/edfSt";
clntNameToService["l_srv_srv"]="\/l_pod\/service\/serve";

## Service file names for a given service
declare -A clntNameToSRV;
clntNameToSRV["r_srv_lp"]="LevelPositions";
clntNameToSRV["l_srv_es"]="EdfState";
clntNameToSRV["l_srv_srv"]="Serve";


## Service file name in C++ header
declare -A clntNameToHeaderName;
clntNameToHeaderName["r_srv_lp"]="level_positions";
clntNameToHeaderName["l_srv_es"]="edf_state";
clntNameToHeaderName["l_srv_srv"]="serve";

# KDB function to call if necessary
declare -A clntNameToKdbFunc;
clntNameToKdbFunc["r_srv_lp"]="rosLevelPositions";
clntNameToKdbFunc["l_srv_es"]="rosEdfState";
clntNameToKdbFunc["l_srv_srv"]="rosServe";


## ================================================================================================== ##
## Define the dictionary of datatype to KDB conversion function
## ================================================================================================== ##

declare -A CtoKDBConvertor;
declare -A KDBToCConvertor;

CtoKDBConvertor["float64"]="kf";
CtoKDBConvertor["int64"]="ki";
CtoKDBConvertor["string"]="kS";
CtoKDBConvertor["bool"]="kb";

KDBToCConvertor["float64"]="kF";
KDBToCConvertor["int64"]="kI";
KDBToCConvertor["string"]="kS";
KDBToCConvertor["bool"]="kb";

KDBToCAccessor["float"]="f";
