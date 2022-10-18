# ROS2KDB
Generic ROS2 Package that allows communication with KDB+. 
Contains builds to:
* Publish KDB messages
* Subscribe KDB messages
* KDB Client requests Service response
* KDB Server responds to Service request

Currently, the code is written for a package called racer_interfaces located in the same src directory as the ros2kdb package

## Installation Instructions

Set the Package's directory as ROS2KDB_DIR. 

    export ROS2KDB_DIR=~/cloud/ros_ws/src/ros2kdb/

Set the Package's other directories. These are mostly used by the q qackage

    export CONFIG_DIR=~/cloud/ros_ws/src/ros2kdb/config/
    export INTERFACES_DIR=~/cloud/ros_ws/src/racer_interfaces/
    export QROS_DIR=~/cloud/ros_ws/src/ros2kdb/q

Use the below commands to create the C++ scripts

    cd $ROS2KDB_DIR;bash ./src/buildScripts/buildPublisher.sh 1  $ROS2KDB_DIR/src/definitions.sh;
    cd $ROS2KDB_DIR;bash ./src/buildScripts/buildSubscriber.sh 1 $ROS2KDB_DIR/src/definitions.sh;
    cd $ROS2KDB_DIR;bash ./src/buildScripts/buildClient.sh 1     $ROS2KDB_DIR/src/definitions.sh;
    cd $ROS2KDB_DIR;bash ./src/buildScripts/buildServer.sh 1     $ROS2KDB_DIR/src/definitions.sh;

## Running Publisher/Subscriber Nodes

Open 4 terminals and run one of the following in each. Start the KDB processes first:

    cd $ROS2KDB_DIR;q q/rosSub.q -p 1234 #Topic Subscriber
    cd $ROS2KDB_DIR;q q/rosPub.q -p 2345 #Topic Publisher
    cd $ROS2KDB_DIR/../..;. install/setup.bash;echo done;ros2 run ros2kdb kdbsub
    cd $ROS2KDB_DIR/../..;. install/setup.bash;echo done;ros2 run ros2kdb kdbpub

In the window of the Publisher q process, run the command: 

    .ros.send[`$"publish_l_eng_actuate";1 2 3 4 5i];

check the table l_eng_actuate in the Subscriber KDB+ process and see the data has been added to the table.

## Running Service Server/Client Nodes


Open 4 terminals and run one of the following in each. Start the KDB processes first:

    cd $ROS2KDB_DIR; q q/rosSvcSrv.q -p 3456 #Service Server
    cd $ROS2KDB_DIR; q q/rosSvcClnt.q -p 4567 #Service Client
    cd $ROS2KDB_DIR/../..; . install/setup.bash;echo done;ros2 run ros2kdb kdbsvr
    cd $ROS2KDB_DIR/../..; . install/setup.bash;echo done;ros2 run ros2kdb kdbclnt

In the window of the Client q process, run the command: 

    .ros.clientRequest[`l_srv_srv;4 5j]

```TODO::```
  * Add loop to connection handle to wait until connection created
  * Add handle drop logic to C++ scripts
  * Add error control to all functions to handle incorrect values
  * Add column of message/service package name to pub/sub/clnt/svc CSVs to remove from definitions.sh
  * Add KDB logic to handle reconnects which call the init function, set initialised flag if it is, then if called again just update handle, keep the tables as they are