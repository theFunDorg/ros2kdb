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

## Array mapping ROS2 message file datatype to its KDB variable creator
declare -A CtoKDBConvertor;
  ## ROS2 Messages use uint8 datatype for booleans
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
  ## ROS2 messages use X for strings
CtoKDBConvertor["string"]="ks";


## Array mapping ROS2 message file datatype to its KDB list accessor
declare -A KDBToCConvertor;
  ## ROS2 Messages use uint8 datatype for booleans
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
  ## ROS2 messages use X for strings
KDBToCConvertor["string"]="S";

## Array mapping ROS2 message file datatype to its KDB variable accessor
declare -A KDBToCAccessor;
  ## ROS2 Messages use uint8 datatype for booleans
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
  ## ROS2 messages use X for strings
KDBToCAccessor["string"]="s";

# TYPE  LA     VC    AA
#short  kH()   kh()  ->h
#int    kI()   ki()  ->i
#long   kJ()   kj()  ->j
#float  kF()   kf()  ->f


##ROS2 DATATYPES TO MANAGE!!
#Primitive Type	Serialization	         C++	         KDB+   
#bool (1)	unsigned 8-bit int	         uint8_t (2)     short
#int8	    signed 8-bit int	         int8_t	int      short
#uint8	    unsigned 8-bit int	         uint8_t	     short
#int16	    signed 16-bit int	         int16_t	     short
#uint16	    unsigned 16-bit int	         uint16_t	     short

#int32	    signed 32-bit int	         int32_t	     int
#uint32	    unsigned 32-bit int	         uint32_t	     int
#int64	    signed 64-bit int	         int64_t	     long
#uint64	    unsigned 64-bit int	         uint64_t	     long
#float32    32-bit IEEE float	         float	float	 float
#float64    64-bit IEEE float	         double	float	 float
#string	    ascii string (4)	         std::string     ???

# bool
# byte
# char
# string
# time
# secs/nsecs unsigned 32-bit ints
# ros::Time
# duration
# secs/nsecs signed 32-bit ints
# ros::Duration