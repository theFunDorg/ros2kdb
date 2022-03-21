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
find_package(std_msgs REQUIRED)
find_package(rosidl_default_generators REQUIRED)
find_package(podracer_interfaces REQUIRED)

##rosidl_generate_interfaces(ros2kdb
##  "msg/Antenna.msg"  
##  "msg/EdfInput.msg"  
##  "msg/EdfOutput.msg"  
##  "msg/ElevonInput.msg"  
##  "msg/ElevonOutput.msg"  
##  "msg/ExhaustInput.msg"
##  "msg/ExhaustOutput.msg"  
##  "msg/Locate.msg"
##)
# uncomment the following section in order to fill in
# further dependencies manually.
# find_package(<dependency> REQUIRED)

add_executable(kdbsub 
	src/newSubKdb.cpp
	include/c.o
	)
ament_target_dependencies(kdbsub rclcpp std_msgs podracer_interfaces)

#add_executable(kdbpub 
#	src/kdbpub.cpp
#	include/c.o
#	)
#ament_target_dependencies(kdbpub rclcpp std_msgs)

target_include_directories(kdbsub
	PRIVATE
        "./include"
	)

#target_include_directories(kdbpub
#        PRIVATE
#        "./include"
#	)

install(TARGETS
#  kdbpub
  kdbsub
  DESTINATION lib/${PROJECT_NAME})

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # uncomment the line when a copyright and license is not present in all source files
  #set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # uncomment the line when this package is not in a git repo
  #set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
