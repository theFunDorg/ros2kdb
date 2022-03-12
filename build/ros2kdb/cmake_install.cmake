# Install script for directory: /mnt/c/Users/SCoug/OneDrive/wsl/ros_ws/src/ros2kdb

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/mnt/c/Users/SCoug/OneDrive/wsl/ros_ws/src/ros2kdb/install/ros2kdb")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/ament_index/resource_index/rosidl_interfaces" TYPE FILE FILES "/mnt/c/Users/SCoug/OneDrive/wsl/ros_ws/src/ros2kdb/build/ros2kdb/ament_cmake_index/share/ament_index/resource_index/rosidl_interfaces/ros2kdb")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ros2kdb" TYPE DIRECTORY FILES "/mnt/c/Users/SCoug/OneDrive/wsl/ros_ws/src/ros2kdb/build/ros2kdb/rosidl_generator_c/ros2kdb/" REGEX "/[^/]*\\.h$")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/ros2kdb/environment" TYPE FILE FILES "/opt/ros/galactic/lib/python3.8/site-packages/ament_package/template/environment_hook/library_path.sh")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/ros2kdb/environment" TYPE FILE FILES "/mnt/c/Users/SCoug/OneDrive/wsl/ros_ws/src/ros2kdb/build/ros2kdb/ament_cmake_environment_hooks/library_path.dsv")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libros2kdb__rosidl_generator_c.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libros2kdb__rosidl_generator_c.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libros2kdb__rosidl_generator_c.so"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/mnt/c/Users/SCoug/OneDrive/wsl/ros_ws/src/ros2kdb/build/ros2kdb/libros2kdb__rosidl_generator_c.so")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libros2kdb__rosidl_generator_c.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libros2kdb__rosidl_generator_c.so")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libros2kdb__rosidl_generator_c.so"
         OLD_RPATH "/opt/ros/galactic/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libros2kdb__rosidl_generator_c.so")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ros2kdb" TYPE DIRECTORY FILES "/mnt/c/Users/SCoug/OneDrive/wsl/ros_ws/src/ros2kdb/build/ros2kdb/rosidl_typesupport_fastrtps_c/ros2kdb/" REGEX "/[^/]*\\.cpp$" EXCLUDE)
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libros2kdb__rosidl_typesupport_fastrtps_c.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libros2kdb__rosidl_typesupport_fastrtps_c.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libros2kdb__rosidl_typesupport_fastrtps_c.so"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/mnt/c/Users/SCoug/OneDrive/wsl/ros_ws/src/ros2kdb/build/ros2kdb/libros2kdb__rosidl_typesupport_fastrtps_c.so")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libros2kdb__rosidl_typesupport_fastrtps_c.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libros2kdb__rosidl_typesupport_fastrtps_c.so")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libros2kdb__rosidl_typesupport_fastrtps_c.so"
         OLD_RPATH "/opt/ros/galactic/lib:/mnt/c/Users/SCoug/OneDrive/wsl/ros_ws/src/ros2kdb/build/ros2kdb:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libros2kdb__rosidl_typesupport_fastrtps_c.so")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ros2kdb" TYPE DIRECTORY FILES "/mnt/c/Users/SCoug/OneDrive/wsl/ros_ws/src/ros2kdb/build/ros2kdb/rosidl_typesupport_fastrtps_cpp/ros2kdb/" REGEX "/[^/]*\\.cpp$" EXCLUDE)
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libros2kdb__rosidl_typesupport_fastrtps_cpp.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libros2kdb__rosidl_typesupport_fastrtps_cpp.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libros2kdb__rosidl_typesupport_fastrtps_cpp.so"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/mnt/c/Users/SCoug/OneDrive/wsl/ros_ws/src/ros2kdb/build/ros2kdb/libros2kdb__rosidl_typesupport_fastrtps_cpp.so")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libros2kdb__rosidl_typesupport_fastrtps_cpp.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libros2kdb__rosidl_typesupport_fastrtps_cpp.so")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libros2kdb__rosidl_typesupport_fastrtps_cpp.so"
         OLD_RPATH "/opt/ros/galactic/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libros2kdb__rosidl_typesupport_fastrtps_cpp.so")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ros2kdb" TYPE DIRECTORY FILES "/mnt/c/Users/SCoug/OneDrive/wsl/ros_ws/src/ros2kdb/build/ros2kdb/rosidl_typesupport_introspection_c/ros2kdb/" REGEX "/[^/]*\\.h$")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libros2kdb__rosidl_typesupport_introspection_c.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libros2kdb__rosidl_typesupport_introspection_c.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libros2kdb__rosidl_typesupport_introspection_c.so"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/mnt/c/Users/SCoug/OneDrive/wsl/ros_ws/src/ros2kdb/build/ros2kdb/libros2kdb__rosidl_typesupport_introspection_c.so")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libros2kdb__rosidl_typesupport_introspection_c.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libros2kdb__rosidl_typesupport_introspection_c.so")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libros2kdb__rosidl_typesupport_introspection_c.so"
         OLD_RPATH "/mnt/c/Users/SCoug/OneDrive/wsl/ros_ws/src/ros2kdb/build/ros2kdb:/opt/ros/galactic/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libros2kdb__rosidl_typesupport_introspection_c.so")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libros2kdb__rosidl_typesupport_c.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libros2kdb__rosidl_typesupport_c.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libros2kdb__rosidl_typesupport_c.so"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/mnt/c/Users/SCoug/OneDrive/wsl/ros_ws/src/ros2kdb/build/ros2kdb/libros2kdb__rosidl_typesupport_c.so")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libros2kdb__rosidl_typesupport_c.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libros2kdb__rosidl_typesupport_c.so")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libros2kdb__rosidl_typesupport_c.so"
         OLD_RPATH "/opt/ros/galactic/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libros2kdb__rosidl_typesupport_c.so")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ros2kdb" TYPE DIRECTORY FILES "/mnt/c/Users/SCoug/OneDrive/wsl/ros_ws/src/ros2kdb/build/ros2kdb/rosidl_generator_cpp/ros2kdb/" REGEX "/[^/]*\\.hpp$")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ros2kdb" TYPE DIRECTORY FILES "/mnt/c/Users/SCoug/OneDrive/wsl/ros_ws/src/ros2kdb/build/ros2kdb/rosidl_typesupport_introspection_cpp/ros2kdb/" REGEX "/[^/]*\\.hpp$")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libros2kdb__rosidl_typesupport_introspection_cpp.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libros2kdb__rosidl_typesupport_introspection_cpp.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libros2kdb__rosidl_typesupport_introspection_cpp.so"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/mnt/c/Users/SCoug/OneDrive/wsl/ros_ws/src/ros2kdb/build/ros2kdb/libros2kdb__rosidl_typesupport_introspection_cpp.so")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libros2kdb__rosidl_typesupport_introspection_cpp.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libros2kdb__rosidl_typesupport_introspection_cpp.so")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libros2kdb__rosidl_typesupport_introspection_cpp.so"
         OLD_RPATH "/opt/ros/galactic/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libros2kdb__rosidl_typesupport_introspection_cpp.so")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libros2kdb__rosidl_typesupport_cpp.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libros2kdb__rosidl_typesupport_cpp.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libros2kdb__rosidl_typesupport_cpp.so"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/mnt/c/Users/SCoug/OneDrive/wsl/ros_ws/src/ros2kdb/build/ros2kdb/libros2kdb__rosidl_typesupport_cpp.so")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libros2kdb__rosidl_typesupport_cpp.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libros2kdb__rosidl_typesupport_cpp.so")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libros2kdb__rosidl_typesupport_cpp.so"
         OLD_RPATH "/opt/ros/galactic/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libros2kdb__rosidl_typesupport_cpp.so")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/ros2kdb/environment" TYPE FILE FILES "/mnt/c/Users/SCoug/OneDrive/wsl/ros_ws/src/ros2kdb/build/ros2kdb/ament_cmake_environment_hooks/pythonpath.sh")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/ros2kdb/environment" TYPE FILE FILES "/mnt/c/Users/SCoug/OneDrive/wsl/ros_ws/src/ros2kdb/build/ros2kdb/ament_cmake_environment_hooks/pythonpath.dsv")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/python3.8/site-packages/ros2kdb" TYPE FILE FILES "/mnt/c/Users/SCoug/OneDrive/wsl/ros_ws/src/ros2kdb/build/ros2kdb/rosidl_generator_py/ros2kdb/__init__.py")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  execute_process(
        COMMAND
        "/usr/bin/python3" "-m" "compileall"
        "/mnt/c/Users/SCoug/OneDrive/wsl/ros_ws/src/ros2kdb/install/ros2kdb/lib/python3.8/site-packages/ros2kdb/__init__.py"
      )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/python3.8/site-packages/ros2kdb/msg" TYPE DIRECTORY FILES "/mnt/c/Users/SCoug/OneDrive/wsl/ros_ws/src/ros2kdb/build/ros2kdb/rosidl_generator_py/ros2kdb/msg/" REGEX "/[^/]*\\.py$")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/python3.8/site-packages/ros2kdb/ros2kdb_s__rosidl_typesupport_fastrtps_c.cpython-38-x86_64-linux-gnu.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/python3.8/site-packages/ros2kdb/ros2kdb_s__rosidl_typesupport_fastrtps_c.cpython-38-x86_64-linux-gnu.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/python3.8/site-packages/ros2kdb/ros2kdb_s__rosidl_typesupport_fastrtps_c.cpython-38-x86_64-linux-gnu.so"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/python3.8/site-packages/ros2kdb" TYPE SHARED_LIBRARY FILES "/mnt/c/Users/SCoug/OneDrive/wsl/ros_ws/src/ros2kdb/build/ros2kdb/rosidl_generator_py/ros2kdb/ros2kdb_s__rosidl_typesupport_fastrtps_c.cpython-38-x86_64-linux-gnu.so")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/python3.8/site-packages/ros2kdb/ros2kdb_s__rosidl_typesupport_fastrtps_c.cpython-38-x86_64-linux-gnu.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/python3.8/site-packages/ros2kdb/ros2kdb_s__rosidl_typesupport_fastrtps_c.cpython-38-x86_64-linux-gnu.so")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/python3.8/site-packages/ros2kdb/ros2kdb_s__rosidl_typesupport_fastrtps_c.cpython-38-x86_64-linux-gnu.so"
         OLD_RPATH "/mnt/c/Users/SCoug/OneDrive/wsl/ros_ws/src/ros2kdb/build/ros2kdb/rosidl_generator_py/ros2kdb:/mnt/c/Users/SCoug/OneDrive/wsl/ros_ws/src/ros2kdb/build/ros2kdb:/opt/ros/galactic/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/python3.8/site-packages/ros2kdb/ros2kdb_s__rosidl_typesupport_fastrtps_c.cpython-38-x86_64-linux-gnu.so")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/python3.8/site-packages/ros2kdb/ros2kdb_s__rosidl_typesupport_introspection_c.cpython-38-x86_64-linux-gnu.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/python3.8/site-packages/ros2kdb/ros2kdb_s__rosidl_typesupport_introspection_c.cpython-38-x86_64-linux-gnu.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/python3.8/site-packages/ros2kdb/ros2kdb_s__rosidl_typesupport_introspection_c.cpython-38-x86_64-linux-gnu.so"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/python3.8/site-packages/ros2kdb" TYPE SHARED_LIBRARY FILES "/mnt/c/Users/SCoug/OneDrive/wsl/ros_ws/src/ros2kdb/build/ros2kdb/rosidl_generator_py/ros2kdb/ros2kdb_s__rosidl_typesupport_introspection_c.cpython-38-x86_64-linux-gnu.so")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/python3.8/site-packages/ros2kdb/ros2kdb_s__rosidl_typesupport_introspection_c.cpython-38-x86_64-linux-gnu.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/python3.8/site-packages/ros2kdb/ros2kdb_s__rosidl_typesupport_introspection_c.cpython-38-x86_64-linux-gnu.so")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/python3.8/site-packages/ros2kdb/ros2kdb_s__rosidl_typesupport_introspection_c.cpython-38-x86_64-linux-gnu.so"
         OLD_RPATH "/mnt/c/Users/SCoug/OneDrive/wsl/ros_ws/src/ros2kdb/build/ros2kdb/rosidl_generator_py/ros2kdb:/mnt/c/Users/SCoug/OneDrive/wsl/ros_ws/src/ros2kdb/build/ros2kdb:/opt/ros/galactic/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/python3.8/site-packages/ros2kdb/ros2kdb_s__rosidl_typesupport_introspection_c.cpython-38-x86_64-linux-gnu.so")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/python3.8/site-packages/ros2kdb/ros2kdb_s__rosidl_typesupport_c.cpython-38-x86_64-linux-gnu.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/python3.8/site-packages/ros2kdb/ros2kdb_s__rosidl_typesupport_c.cpython-38-x86_64-linux-gnu.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/python3.8/site-packages/ros2kdb/ros2kdb_s__rosidl_typesupport_c.cpython-38-x86_64-linux-gnu.so"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/python3.8/site-packages/ros2kdb" TYPE SHARED_LIBRARY FILES "/mnt/c/Users/SCoug/OneDrive/wsl/ros_ws/src/ros2kdb/build/ros2kdb/rosidl_generator_py/ros2kdb/ros2kdb_s__rosidl_typesupport_c.cpython-38-x86_64-linux-gnu.so")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/python3.8/site-packages/ros2kdb/ros2kdb_s__rosidl_typesupport_c.cpython-38-x86_64-linux-gnu.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/python3.8/site-packages/ros2kdb/ros2kdb_s__rosidl_typesupport_c.cpython-38-x86_64-linux-gnu.so")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/python3.8/site-packages/ros2kdb/ros2kdb_s__rosidl_typesupport_c.cpython-38-x86_64-linux-gnu.so"
         OLD_RPATH "/mnt/c/Users/SCoug/OneDrive/wsl/ros_ws/src/ros2kdb/build/ros2kdb/rosidl_generator_py/ros2kdb:/mnt/c/Users/SCoug/OneDrive/wsl/ros_ws/src/ros2kdb/build/ros2kdb:/opt/ros/galactic/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/python3.8/site-packages/ros2kdb/ros2kdb_s__rosidl_typesupport_c.cpython-38-x86_64-linux-gnu.so")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libros2kdb__python.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libros2kdb__python.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libros2kdb__python.so"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/mnt/c/Users/SCoug/OneDrive/wsl/ros_ws/src/ros2kdb/build/ros2kdb/rosidl_generator_py/ros2kdb/libros2kdb__python.so")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libros2kdb__python.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libros2kdb__python.so")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libros2kdb__python.so"
         OLD_RPATH "/mnt/c/Users/SCoug/OneDrive/wsl/ros_ws/src/ros2kdb/build/ros2kdb:/opt/ros/galactic/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libros2kdb__python.so")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/ros2kdb/msg" TYPE FILE FILES "/mnt/c/Users/SCoug/OneDrive/wsl/ros_ws/src/ros2kdb/build/ros2kdb/rosidl_adapter/ros2kdb/msg/Antenna.idl")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/ros2kdb/msg" TYPE FILE FILES "/mnt/c/Users/SCoug/OneDrive/wsl/ros_ws/src/ros2kdb/build/ros2kdb/rosidl_adapter/ros2kdb/msg/EdfInput.idl")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/ros2kdb/msg" TYPE FILE FILES "/mnt/c/Users/SCoug/OneDrive/wsl/ros_ws/src/ros2kdb/build/ros2kdb/rosidl_adapter/ros2kdb/msg/EdfOutput.idl")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/ros2kdb/msg" TYPE FILE FILES "/mnt/c/Users/SCoug/OneDrive/wsl/ros_ws/src/ros2kdb/build/ros2kdb/rosidl_adapter/ros2kdb/msg/ElevonInput.idl")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/ros2kdb/msg" TYPE FILE FILES "/mnt/c/Users/SCoug/OneDrive/wsl/ros_ws/src/ros2kdb/build/ros2kdb/rosidl_adapter/ros2kdb/msg/ElevonOutput.idl")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/ros2kdb/msg" TYPE FILE FILES "/mnt/c/Users/SCoug/OneDrive/wsl/ros_ws/src/ros2kdb/build/ros2kdb/rosidl_adapter/ros2kdb/msg/ExhaustInput.idl")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/ros2kdb/msg" TYPE FILE FILES "/mnt/c/Users/SCoug/OneDrive/wsl/ros_ws/src/ros2kdb/build/ros2kdb/rosidl_adapter/ros2kdb/msg/ExhaustOutput.idl")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/ros2kdb/msg" TYPE FILE FILES "/mnt/c/Users/SCoug/OneDrive/wsl/ros_ws/src/ros2kdb/build/ros2kdb/rosidl_adapter/ros2kdb/msg/Locate.idl")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/ros2kdb/msg" TYPE FILE FILES "/mnt/c/Users/SCoug/OneDrive/wsl/ros_ws/src/ros2kdb/msg/Antenna.msg")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/ros2kdb/msg" TYPE FILE FILES "/mnt/c/Users/SCoug/OneDrive/wsl/ros_ws/src/ros2kdb/msg/EdfInput.msg")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/ros2kdb/msg" TYPE FILE FILES "/mnt/c/Users/SCoug/OneDrive/wsl/ros_ws/src/ros2kdb/msg/EdfOutput.msg")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/ros2kdb/msg" TYPE FILE FILES "/mnt/c/Users/SCoug/OneDrive/wsl/ros_ws/src/ros2kdb/msg/ElevonInput.msg")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/ros2kdb/msg" TYPE FILE FILES "/mnt/c/Users/SCoug/OneDrive/wsl/ros_ws/src/ros2kdb/msg/ElevonOutput.msg")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/ros2kdb/msg" TYPE FILE FILES "/mnt/c/Users/SCoug/OneDrive/wsl/ros_ws/src/ros2kdb/msg/ExhaustInput.msg")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/ros2kdb/msg" TYPE FILE FILES "/mnt/c/Users/SCoug/OneDrive/wsl/ros_ws/src/ros2kdb/msg/ExhaustOutput.msg")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/ros2kdb/msg" TYPE FILE FILES "/mnt/c/Users/SCoug/OneDrive/wsl/ros_ws/src/ros2kdb/msg/Locate.msg")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/ros2kdb/kdbsub" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/ros2kdb/kdbsub")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/ros2kdb/kdbsub"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/ros2kdb" TYPE EXECUTABLE FILES "/mnt/c/Users/SCoug/OneDrive/wsl/ros_ws/src/ros2kdb/build/ros2kdb/kdbsub")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/ros2kdb/kdbsub" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/ros2kdb/kdbsub")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/ros2kdb/kdbsub"
         OLD_RPATH "/opt/ros/galactic/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/ros2kdb/kdbsub")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/ament_index/resource_index/package_run_dependencies" TYPE FILE FILES "/mnt/c/Users/SCoug/OneDrive/wsl/ros_ws/src/ros2kdb/build/ros2kdb/ament_cmake_index/share/ament_index/resource_index/package_run_dependencies/ros2kdb")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/ament_index/resource_index/parent_prefix_path" TYPE FILE FILES "/mnt/c/Users/SCoug/OneDrive/wsl/ros_ws/src/ros2kdb/build/ros2kdb/ament_cmake_index/share/ament_index/resource_index/parent_prefix_path/ros2kdb")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/ros2kdb/environment" TYPE FILE FILES "/opt/ros/galactic/share/ament_cmake_core/cmake/environment_hooks/environment/ament_prefix_path.sh")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/ros2kdb/environment" TYPE FILE FILES "/mnt/c/Users/SCoug/OneDrive/wsl/ros_ws/src/ros2kdb/build/ros2kdb/ament_cmake_environment_hooks/ament_prefix_path.dsv")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/ros2kdb/environment" TYPE FILE FILES "/opt/ros/galactic/share/ament_cmake_core/cmake/environment_hooks/environment/path.sh")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/ros2kdb/environment" TYPE FILE FILES "/mnt/c/Users/SCoug/OneDrive/wsl/ros_ws/src/ros2kdb/build/ros2kdb/ament_cmake_environment_hooks/path.dsv")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/ros2kdb" TYPE FILE FILES "/mnt/c/Users/SCoug/OneDrive/wsl/ros_ws/src/ros2kdb/build/ros2kdb/ament_cmake_environment_hooks/local_setup.bash")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/ros2kdb" TYPE FILE FILES "/mnt/c/Users/SCoug/OneDrive/wsl/ros_ws/src/ros2kdb/build/ros2kdb/ament_cmake_environment_hooks/local_setup.sh")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/ros2kdb" TYPE FILE FILES "/mnt/c/Users/SCoug/OneDrive/wsl/ros_ws/src/ros2kdb/build/ros2kdb/ament_cmake_environment_hooks/local_setup.zsh")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/ros2kdb" TYPE FILE FILES "/mnt/c/Users/SCoug/OneDrive/wsl/ros_ws/src/ros2kdb/build/ros2kdb/ament_cmake_environment_hooks/local_setup.dsv")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/ros2kdb" TYPE FILE FILES "/mnt/c/Users/SCoug/OneDrive/wsl/ros_ws/src/ros2kdb/build/ros2kdb/ament_cmake_environment_hooks/package.dsv")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/ament_index/resource_index/packages" TYPE FILE FILES "/mnt/c/Users/SCoug/OneDrive/wsl/ros_ws/src/ros2kdb/build/ros2kdb/ament_cmake_index/share/ament_index/resource_index/packages/ros2kdb")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/ros2kdb/cmake/ros2kdb__rosidl_generator_cExport.cmake")
    file(DIFFERENT EXPORT_FILE_CHANGED FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/ros2kdb/cmake/ros2kdb__rosidl_generator_cExport.cmake"
         "/mnt/c/Users/SCoug/OneDrive/wsl/ros_ws/src/ros2kdb/build/ros2kdb/CMakeFiles/Export/share/ros2kdb/cmake/ros2kdb__rosidl_generator_cExport.cmake")
    if(EXPORT_FILE_CHANGED)
      file(GLOB OLD_CONFIG_FILES "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/ros2kdb/cmake/ros2kdb__rosidl_generator_cExport-*.cmake")
      if(OLD_CONFIG_FILES)
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/ros2kdb/cmake/ros2kdb__rosidl_generator_cExport.cmake\" will be replaced.  Removing files [${OLD_CONFIG_FILES}].")
        file(REMOVE ${OLD_CONFIG_FILES})
      endif()
    endif()
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/ros2kdb/cmake" TYPE FILE FILES "/mnt/c/Users/SCoug/OneDrive/wsl/ros_ws/src/ros2kdb/build/ros2kdb/CMakeFiles/Export/share/ros2kdb/cmake/ros2kdb__rosidl_generator_cExport.cmake")
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^()$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/ros2kdb/cmake" TYPE FILE FILES "/mnt/c/Users/SCoug/OneDrive/wsl/ros_ws/src/ros2kdb/build/ros2kdb/CMakeFiles/Export/share/ros2kdb/cmake/ros2kdb__rosidl_generator_cExport-noconfig.cmake")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/ros2kdb/cmake/ros2kdb__rosidl_typesupport_introspection_cExport.cmake")
    file(DIFFERENT EXPORT_FILE_CHANGED FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/ros2kdb/cmake/ros2kdb__rosidl_typesupport_introspection_cExport.cmake"
         "/mnt/c/Users/SCoug/OneDrive/wsl/ros_ws/src/ros2kdb/build/ros2kdb/CMakeFiles/Export/share/ros2kdb/cmake/ros2kdb__rosidl_typesupport_introspection_cExport.cmake")
    if(EXPORT_FILE_CHANGED)
      file(GLOB OLD_CONFIG_FILES "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/ros2kdb/cmake/ros2kdb__rosidl_typesupport_introspection_cExport-*.cmake")
      if(OLD_CONFIG_FILES)
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/ros2kdb/cmake/ros2kdb__rosidl_typesupport_introspection_cExport.cmake\" will be replaced.  Removing files [${OLD_CONFIG_FILES}].")
        file(REMOVE ${OLD_CONFIG_FILES})
      endif()
    endif()
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/ros2kdb/cmake" TYPE FILE FILES "/mnt/c/Users/SCoug/OneDrive/wsl/ros_ws/src/ros2kdb/build/ros2kdb/CMakeFiles/Export/share/ros2kdb/cmake/ros2kdb__rosidl_typesupport_introspection_cExport.cmake")
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^()$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/ros2kdb/cmake" TYPE FILE FILES "/mnt/c/Users/SCoug/OneDrive/wsl/ros_ws/src/ros2kdb/build/ros2kdb/CMakeFiles/Export/share/ros2kdb/cmake/ros2kdb__rosidl_typesupport_introspection_cExport-noconfig.cmake")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/ros2kdb/cmake/ros2kdb__rosidl_typesupport_cExport.cmake")
    file(DIFFERENT EXPORT_FILE_CHANGED FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/ros2kdb/cmake/ros2kdb__rosidl_typesupport_cExport.cmake"
         "/mnt/c/Users/SCoug/OneDrive/wsl/ros_ws/src/ros2kdb/build/ros2kdb/CMakeFiles/Export/share/ros2kdb/cmake/ros2kdb__rosidl_typesupport_cExport.cmake")
    if(EXPORT_FILE_CHANGED)
      file(GLOB OLD_CONFIG_FILES "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/ros2kdb/cmake/ros2kdb__rosidl_typesupport_cExport-*.cmake")
      if(OLD_CONFIG_FILES)
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/ros2kdb/cmake/ros2kdb__rosidl_typesupport_cExport.cmake\" will be replaced.  Removing files [${OLD_CONFIG_FILES}].")
        file(REMOVE ${OLD_CONFIG_FILES})
      endif()
    endif()
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/ros2kdb/cmake" TYPE FILE FILES "/mnt/c/Users/SCoug/OneDrive/wsl/ros_ws/src/ros2kdb/build/ros2kdb/CMakeFiles/Export/share/ros2kdb/cmake/ros2kdb__rosidl_typesupport_cExport.cmake")
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^()$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/ros2kdb/cmake" TYPE FILE FILES "/mnt/c/Users/SCoug/OneDrive/wsl/ros_ws/src/ros2kdb/build/ros2kdb/CMakeFiles/Export/share/ros2kdb/cmake/ros2kdb__rosidl_typesupport_cExport-noconfig.cmake")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/ros2kdb/cmake/ros2kdb__rosidl_generator_cppExport.cmake")
    file(DIFFERENT EXPORT_FILE_CHANGED FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/ros2kdb/cmake/ros2kdb__rosidl_generator_cppExport.cmake"
         "/mnt/c/Users/SCoug/OneDrive/wsl/ros_ws/src/ros2kdb/build/ros2kdb/CMakeFiles/Export/share/ros2kdb/cmake/ros2kdb__rosidl_generator_cppExport.cmake")
    if(EXPORT_FILE_CHANGED)
      file(GLOB OLD_CONFIG_FILES "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/ros2kdb/cmake/ros2kdb__rosidl_generator_cppExport-*.cmake")
      if(OLD_CONFIG_FILES)
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/ros2kdb/cmake/ros2kdb__rosidl_generator_cppExport.cmake\" will be replaced.  Removing files [${OLD_CONFIG_FILES}].")
        file(REMOVE ${OLD_CONFIG_FILES})
      endif()
    endif()
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/ros2kdb/cmake" TYPE FILE FILES "/mnt/c/Users/SCoug/OneDrive/wsl/ros_ws/src/ros2kdb/build/ros2kdb/CMakeFiles/Export/share/ros2kdb/cmake/ros2kdb__rosidl_generator_cppExport.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/ros2kdb/cmake/ros2kdb__rosidl_typesupport_introspection_cppExport.cmake")
    file(DIFFERENT EXPORT_FILE_CHANGED FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/ros2kdb/cmake/ros2kdb__rosidl_typesupport_introspection_cppExport.cmake"
         "/mnt/c/Users/SCoug/OneDrive/wsl/ros_ws/src/ros2kdb/build/ros2kdb/CMakeFiles/Export/share/ros2kdb/cmake/ros2kdb__rosidl_typesupport_introspection_cppExport.cmake")
    if(EXPORT_FILE_CHANGED)
      file(GLOB OLD_CONFIG_FILES "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/ros2kdb/cmake/ros2kdb__rosidl_typesupport_introspection_cppExport-*.cmake")
      if(OLD_CONFIG_FILES)
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/ros2kdb/cmake/ros2kdb__rosidl_typesupport_introspection_cppExport.cmake\" will be replaced.  Removing files [${OLD_CONFIG_FILES}].")
        file(REMOVE ${OLD_CONFIG_FILES})
      endif()
    endif()
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/ros2kdb/cmake" TYPE FILE FILES "/mnt/c/Users/SCoug/OneDrive/wsl/ros_ws/src/ros2kdb/build/ros2kdb/CMakeFiles/Export/share/ros2kdb/cmake/ros2kdb__rosidl_typesupport_introspection_cppExport.cmake")
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^()$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/ros2kdb/cmake" TYPE FILE FILES "/mnt/c/Users/SCoug/OneDrive/wsl/ros_ws/src/ros2kdb/build/ros2kdb/CMakeFiles/Export/share/ros2kdb/cmake/ros2kdb__rosidl_typesupport_introspection_cppExport-noconfig.cmake")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/ros2kdb/cmake/ros2kdb__rosidl_typesupport_cppExport.cmake")
    file(DIFFERENT EXPORT_FILE_CHANGED FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/ros2kdb/cmake/ros2kdb__rosidl_typesupport_cppExport.cmake"
         "/mnt/c/Users/SCoug/OneDrive/wsl/ros_ws/src/ros2kdb/build/ros2kdb/CMakeFiles/Export/share/ros2kdb/cmake/ros2kdb__rosidl_typesupport_cppExport.cmake")
    if(EXPORT_FILE_CHANGED)
      file(GLOB OLD_CONFIG_FILES "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/ros2kdb/cmake/ros2kdb__rosidl_typesupport_cppExport-*.cmake")
      if(OLD_CONFIG_FILES)
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/ros2kdb/cmake/ros2kdb__rosidl_typesupport_cppExport.cmake\" will be replaced.  Removing files [${OLD_CONFIG_FILES}].")
        file(REMOVE ${OLD_CONFIG_FILES})
      endif()
    endif()
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/ros2kdb/cmake" TYPE FILE FILES "/mnt/c/Users/SCoug/OneDrive/wsl/ros_ws/src/ros2kdb/build/ros2kdb/CMakeFiles/Export/share/ros2kdb/cmake/ros2kdb__rosidl_typesupport_cppExport.cmake")
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^()$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/ros2kdb/cmake" TYPE FILE FILES "/mnt/c/Users/SCoug/OneDrive/wsl/ros_ws/src/ros2kdb/build/ros2kdb/CMakeFiles/Export/share/ros2kdb/cmake/ros2kdb__rosidl_typesupport_cppExport-noconfig.cmake")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/ros2kdb/cmake" TYPE FILE FILES "/mnt/c/Users/SCoug/OneDrive/wsl/ros_ws/src/ros2kdb/build/ros2kdb/rosidl_cmake/rosidl_cmake-extras.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/ros2kdb/cmake" TYPE FILE FILES "/mnt/c/Users/SCoug/OneDrive/wsl/ros_ws/src/ros2kdb/build/ros2kdb/ament_cmake_export_dependencies/ament_cmake_export_dependencies-extras.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/ros2kdb/cmake" TYPE FILE FILES "/mnt/c/Users/SCoug/OneDrive/wsl/ros_ws/src/ros2kdb/build/ros2kdb/ament_cmake_export_libraries/ament_cmake_export_libraries-extras.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/ros2kdb/cmake" TYPE FILE FILES "/mnt/c/Users/SCoug/OneDrive/wsl/ros_ws/src/ros2kdb/build/ros2kdb/ament_cmake_export_targets/ament_cmake_export_targets-extras.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/ros2kdb/cmake" TYPE FILE FILES "/mnt/c/Users/SCoug/OneDrive/wsl/ros_ws/src/ros2kdb/build/ros2kdb/ament_cmake_export_include_directories/ament_cmake_export_include_directories-extras.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/ros2kdb/cmake" TYPE FILE FILES "/mnt/c/Users/SCoug/OneDrive/wsl/ros_ws/src/ros2kdb/build/ros2kdb/rosidl_cmake/rosidl_cmake_export_typesupport_libraries-extras.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/ros2kdb/cmake" TYPE FILE FILES "/mnt/c/Users/SCoug/OneDrive/wsl/ros_ws/src/ros2kdb/build/ros2kdb/rosidl_cmake/rosidl_cmake_export_typesupport_targets-extras.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/ros2kdb/cmake" TYPE FILE FILES
    "/mnt/c/Users/SCoug/OneDrive/wsl/ros_ws/src/ros2kdb/build/ros2kdb/ament_cmake_core/ros2kdbConfig.cmake"
    "/mnt/c/Users/SCoug/OneDrive/wsl/ros_ws/src/ros2kdb/build/ros2kdb/ament_cmake_core/ros2kdbConfig-version.cmake"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/ros2kdb" TYPE FILE FILES "/mnt/c/Users/SCoug/OneDrive/wsl/ros_ws/src/ros2kdb/package.xml")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/mnt/c/Users/SCoug/OneDrive/wsl/ros_ws/src/ros2kdb/build/ros2kdb/ros2kdb__py/cmake_install.cmake")

endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "/mnt/c/Users/SCoug/OneDrive/wsl/ros_ws/src/ros2kdb/build/ros2kdb/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
