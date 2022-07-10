cmake_minimum_required(VERSION 3.5)
project(ros2kdb)

set(CMAKE_C_STANDARD 99)

set(CMAKE_CXX_STANDARD 17)

add_compile_options(-Wall -Wextra )

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -march=native")
 
 include_directories("./include")
 # find dependencies
 find_package(ament_cmake REQUIRED)
 find_package(rclcpp REQUIRED)
 find_package(rosidl_default_generators REQUIRED)
 find_package(racer_interfaces REQUIRED)

add_executable(kdbsub   src/run/subscribe_1.cpp 	include/c.o)
ament_target_dependencies(kdbsub rclcpp racer_interfaces)
target_include_directories(kdbsub 	 PRIVATE  "./include")

#add_executable(kdbpub   src/run/publish_1.cpp 	include/c.o)
#ament_target_dependencies(kdbpub rclcpp racer_interfaces)
#target_include_directories(kdbpub   PRIVATE  "./include")

#add_executable(kdbsvr   src/run/server_1.cpp	include/c.o)
#ament_target_dependencies(kdbsvr rclcpp racer_interfaces)
#target_include_directories(kdbsvr   PRIVATE  "./include")

#add_executable(kdbclnt   src/run/client_1.cpp	include/c.o)
#ament_target_dependencies(kdbclnt rclcpp racer_interfaces)
#target_include_directories(kdbclnt  PRIVATE  "./include")

install(TARGETS
#  kdbpub
  kdbsub
#  kdbsvr
#  kdbclnt
  DESTINATION lib/${PROJECT_NAME})

ament_package()
