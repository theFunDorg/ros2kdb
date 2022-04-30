# ROS2KDB
Generic ROS2 pub/sub api for KDB

# Instructions
cd ~/cloud/ros_ws
. install/setup.bash;echo done;ros2 run ros2kdb kdbpub
. install/setup.bash;echo done;ros2 run ros2kdb kdbsub
. install/setup.bash;echo done;ros2 run ros2kdb kdbsrv
. install/setup.bash;echo done;ros2 run ros2kdb kdbclnt

q q/ros.q -p 1234 #Topic Publisher
q q/ros.q -p 2345 #Topic Subscriber
q q/ros.q -p 3456 #Service Server
q q/ros.q -p 4567 #Service Client

Right now... 

For Publisher/Subscriber
Open 4 terminals
Run these commands in each:
~/cloud/ros_ws/src/ros2kdb
q q/ros.q -p 1234 #Topic Publisher
q q/ros.q -p 2345 #Topic Subscriber
. install/setup.bash;echo done;ros2 run ros2kdb kdbpub
. install/setup.bash;echo done;ros2 run ros2kdb kdbsub

in the window of port 1234, run the command: 
.ros.send["publish_r_act_ex";(1 2 3 4 5 6 7 8f)];


For Service Server/Client
Open 4 terminals
Run these commands in each 

q q/ros.q -p 3456 #Service Server
q q/ros.q -p 4567 #Service Client
. install/setup.bash;echo done;ros2 run ros2kdb kdbsrv
. install/setup.bash;echo done;ros2 run ros2kdb kdbclnt

.ros.clientRequest[`func_client_serve_kdb;(1;2)]

# TODO
* Parameterise the shell script for package, filepaths, etc
* Correct the shell script to create the correct publisher file
* Add .ros.send, .ros.receive and add their upsert tables too
* Add and test different variable types
* See about creating simple test script
* Add a parser for the message files to create KDB table schemas
* Create file with all the dictionary mappings, maybe as part of above parameterising file?
* add running of shell script to the build job in CMakefile, same with running q script maybe
