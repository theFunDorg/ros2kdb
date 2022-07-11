# ROS2KDB
Generic ROS2 Package that allows communication with KDB+. 
Contains builds to:
* Publish KDB messages
* Subscribe KDB messages
* KDB Client requests Service response
* KDB Server responds to Service request

## Installation Instructions

Set the Package's directory as ROS2KDB_DIR. 

    export ROS2KDB_DIR=~/cloud/ros_ws/src/ros2kdb

Use the below commands to create the C++ scripts

    bash ./src/buildScripts/buildPublisher.sh 1  $ROS2KDB_DIR/src/definitions.sh;
    bash ./src/buildScripts/buildSubscriber.sh 1 $ROS2KDB_DIR/src/definitions.sh;
    bash ./src/buildScripts/buildClient.sh 1     $ROS2KDB_DIR/src/definitions.sh;
    bash ./src/buildScripts/buildServer.sh 1     $ROS2KDB_DIR/src/definitions.sh;

## Running Publisher/Subscriber Nodes

Open 4 terminals and run one of the following in each. Start the KDB processes first:

    cd $ROS2KDB_DIR;q q/ros.q -p 1234 -ROSnode publisher #Topic Publisher
    cd $ROS2KDB_DIR;q q/ros.q -p 2345 -ROSnode subscriber #Topic Subscriber
    . install/setup.bash;echo done;ros2 run ros2kdb kdbpub
    . install/setup.bash;echo done;ros2 run ros2kdb kdbsub

In the window of the Publisher q process, run the command: 

    .ros.send[`$"publish_l_eng_actuate";1 2 3 4 5i];

check the table l_eng_actuate in the Subscriber KDB+ process and see the data has been added to the table.

## Running Service Server/Client Nodes

```TODO: Make below work again... ```

Open 4 terminals and run one of the following in each. Start the KDB processes first:

    cd $ROS2KDB_DIR; q q/ros.q -p 3456 -ROSnode server  #Service Server
    cd $ROS2KDB_DIR; q q/ros.q -p 4567 -ROSnode client  #Service Client
    . install/setup.bash;echo done;ros2 run ros2kdb kdbsvr
    . install/setup.bash;echo done;ros2 run ros2kdb kdbclnt

In the window of the Client q process, run the command: 

    .ros.clientRequest[`l_srv_srv;4 5j]

```TODO::```
  * Add loop to connection handle to wait until connection created
  * Add handle drop logic to C++ scripts
  * Add error control to all functions to handle incorrect values
  * Add column of message/service package name to pub/sub/clnt/svc CSVs to remove from definitions.sh