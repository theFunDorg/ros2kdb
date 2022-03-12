// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from ros2kdb:msg/Antenna.idl
// generated code does not contain a copyright notice

#ifndef ROS2KDB__MSG__DETAIL__ANTENNA__STRUCT_H_
#define ROS2KDB__MSG__DETAIL__ANTENNA__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'data'
#include "rosidl_runtime_c/string.h"

// Struct defined in msg/Antenna in the package ros2kdb.
typedef struct ros2kdb__msg__Antenna
{
  rosidl_runtime_c__String data;
} ros2kdb__msg__Antenna;

// Struct for a sequence of ros2kdb__msg__Antenna.
typedef struct ros2kdb__msg__Antenna__Sequence
{
  ros2kdb__msg__Antenna * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ros2kdb__msg__Antenna__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ROS2KDB__MSG__DETAIL__ANTENNA__STRUCT_H_
