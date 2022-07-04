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
## Subscription/Publisher Params
## ================================================================================================== ##
# Subscription names are used as the key for all values. 

## Topic names for given subscription name
declare -A subNameToTopic;
subNameToTopic["r_act_ex"]="\/r_pod\/actuate\/exhaust";
subNameToTopic["l_act_edf"]="\/l_pod\/actuate\/edf";

## Message file names for a given subscription name
declare -A subNameToMsg;
subNameToMsg["r_act_ex"]="ExhaustInput";
subNameToMsg["l_act_edf"]="EdfInput";

## ================================================================================================== ##
# Service Params 
## ================================================================================================== ##
# Service names are used as the key for all values. 

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

# KDB function to call
declare -A svcNameToKdbFunc;
svcNameToKdbFunc["r_srv_lp"]=".ros.levelPositions";
svcNameToKdbFunc["l_srv_es"]=".ros.edfState";
svcNameToKdbFunc["l_srv_srv"]=".ros.Serve";

## ================================================================================================== ##
# Client Params 
## ================================================================================================== ##
# Client names are used as the key for all values. 

## Client names for given service
declare -A clntNameToService;
clntNameToService["r_srv_lp"]="\/r_pod\/service\/lvPosns";
clntNameToService["l_srv_es"]="\/l_pod\/service\/edfSt";
clntNameToService["l_srv_srv"]="\/l_pod\/service\/serve";

## Service file names for a given service
declare -A clntNameToSRV;
clntNameToSRV["r_srv_lp"]="LevelPositions";
clntNameToSRV["l_srv_es"]="EdfState";
clntNameToSRV["l_srv_srv"]="Serve";

# KDB key to call
declare -A clntNameToKdbFunc;
clntNameToKdbFunc["r_srv_lp"]="rosLevelPositions";
clntNameToKdbFunc["l_srv_es"]="rosEdfState";
clntNameToKdbFunc["l_srv_srv"]="rosServe";

## ================================================================================================== ##
## Define the dictionary of datatype to KDB conversion function
## ================================================================================================== ##

## Array mapping ROS2 message file datatype to its KDB variable creator
declare -A CtoKDBConvertor;
CtoKDBConvertor["bool"]="kh";
CtoKDBConvertor["int8"]="kh";
CtoKDBConvertor["uint8"]="kh";
CtoKDBConvertor["int16"]="kh";
CtoKDBConvertor["uint16"]="kh";
CtoKDBConvertor["int32"]="ki";
CtoKDBConvertor["uint32"]="ki";
CtoKDBConvertor["int64"]="kj";
CtoKDBConvertor["uint64"]="kj";
CtoKDBConvertor["float32"]="kf";
CtoKDBConvertor["float64"]="kf";
CtoKDBConvertor["string"]="ks";

## Array mapping ROS2 message file datatype to its KDB list accessor
declare -A KDBToCConvertor;
KDBToCConvertor["bool"]="kH";
KDBToCConvertor["int8"]="kH";
KDBToCConvertor["uint8"]="kH";
KDBToCConvertor["int16"]="kH";
KDBToCConvertor["uint16"]="kH";
KDBToCConvertor["int32"]="kI";
KDBToCConvertor["uint32"]="kI";
KDBToCConvertor["int64"]="kJ";
KDBToCConvertor["uint64"]="kJ";
KDBToCConvertor["float32"]="kF";
KDBToCConvertor["float64"]="kF";
KDBToCConvertor["string"]="kS";

## Array mapping ROS2 message file datatype to its KDB variable accessor
declare -A KDBToCAccessor;
KDBToCAccessor["bool"]="h";
KDBToCAccessor["int8"]="h";
KDBToCAccessor["uint8"]="h";
KDBToCAccessor["int16"]="h";
KDBToCAccessor["uint16"]="h";
KDBToCAccessor["int32"]="i";
KDBToCAccessor["uint32"]="i";
KDBToCAccessor["int64"]="j";
KDBToCAccessor["uint64"]="j";
KDBToCAccessor["float32"]="f";
KDBToCAccessor["float64"]="f";
KDBToCAccessor["string"]="s";

# TYPE  LA     VC    AA
#short  kH()   kh()  ->h
#int    kI()   ki()  ->i
#long   kJ()   kj()  ->j
#float  kF()   kf()  ->f

##ROS2 DATATYPES TO MANAGE!!
#Primitive Type	Serialization	                  C++	            KDB+   
#string	       ascii string (4)                 std::string     ???
# time         secs/nsecs unsigned 32-bit ints  ros::Time       ???
# duration     secs/nsecs signed 32-bit ints    ros::Duration   ???
# byte
# char