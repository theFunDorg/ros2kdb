# ROS2KDB
Generic ROS2 API for KDB. 
Handles:
* Publish KDB messages
* Subscribe KDB messages
* KDB Client requests Service response
* KDB Server responds to Service request

## Installation Instructions

Set the Package's working directory

    export ROS2KDB_DIR=~/cloud/ros_ws/src/ros2kdb

Use the below commands to create the C++ scripts

    bash ./src/buildScripts/buildPublisher.sh 1  $ROS2KDB_DIR/src/definitions.sh;
    bash ./src/buildScripts/buildSubscriber.sh 1 $ROS2KDB_DIR/src/definitions.sh;
    bash ./src/buildScripts/buildClient.sh 1     $ROS2KDB_DIR/src/definitions.sh;
    bash ./src/buildScripts/buildServer.sh 1     $ROS2KDB_DIR/src/definitions.sh;

## Instructions
To run the ROS2 instances, in 4 terminals Run:

    cd $ROS2KDB_DIR/../../
    . install/setup.bash;echo done;ros2 run ros2kdb kdbpub
    . install/setup.bash;echo done;ros2 run ros2kdb kdbsub
    . install/setup.bash;echo done;ros2 run ros2kdb kdbsrv
    . install/setup.bash;echo done;ros2 run ros2kdb kdbclnt

In 4 terminals, run the following:

    q $ROS2KDB_DIR/q/ros.q -p 1234 #Topic Publisher
    q $ROS2KDB_DIR/q/ros.q -p 2345 #Topic Subscriber
    q $ROS2KDB_DIR/q/ros.q -p 3456 #Service Server
    q $ROS2KDB_DIR/q/ros.q -p 4567 #Service Client

```Right now... ```

For Publisher/Subscriber
Open 4 terminals
Run these commands in each:
cd ~/cloud/ros_ws/src/ros2kdb
q q/ros.q -p 1234 #Topic Publisher
q q/ros.q -p 2345 #Topic Subscriber
. install/setup.bash;echo done;ros2 run ros2kdb kdbpub
. install/setup.bash;echo done;ros2 run ros2kdb kdbsub

in the window of port 1234, run the command: 
.ros.send[`publish_r_act_ex;(),(1 2 3 4 5 6 7 8f)];


For Service Server/Client
Open 4 terminals
Run these commands in each 

q q/ros.q -p 3456 #Service Server
q q/ros.q -p 4567 #Service Client
. install/setup.bash;echo done;ros2 run ros2kdb kdbsrv
. install/setup.bash;echo done;ros2 run ros2kdb kdbclnt

.ros.clientRequest[`func_client_serve_kdb;(1i;2i)]
