# ROS2KDB
Generic ROS2 pub/sub api for KDB

# Instructions
cd ~/cloud/ros_ws
. install/setup.bash;echo done;ros2 run ros2kdb kdbpub
. install/setup.bash;echo done;ros2 run ros2kdb kdbsub
q q/ros.q


# TODO
* Parameterise the shell script for package, filepaths, etc
* Correct the shell script to create the correct publisher file
* Add .ros.send, .ros.receive and add their upsert tables too
* Add and test different variable types
* See about creating simple test script
* Add a parser for the message files to create KDB table schemas
* Create file with all the dictionary mappings, maybe as part of above parameterising file?
* add running of shell script to the build job in CMakefile, same with running q script maybe
