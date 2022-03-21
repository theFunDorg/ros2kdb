// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from ros2kdb:msg/ElevonOutput.idl
// generated code does not contain a copyright notice

#ifndef ROS2KDB__MSG__DETAIL__ELEVON_OUTPUT__STRUCT_H_
#define ROS2KDB__MSG__DETAIL__ELEVON_OUTPUT__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Struct defined in msg/ElevonOutput in the package ros2kdb.
typedef struct ros2kdb__msg__ElevonOutput
{
  double l_pos;
  double r_pos;
} ros2kdb__msg__ElevonOutput;

// Struct for a sequence of ros2kdb__msg__ElevonOutput.
typedef struct ros2kdb__msg__ElevonOutput__Sequence
{
  ros2kdb__msg__ElevonOutput * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ros2kdb__msg__ElevonOutput__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ROS2KDB__MSG__DETAIL__ELEVON_OUTPUT__STRUCT_H_