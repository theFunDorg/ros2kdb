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