// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from ros2kdb:msg/EdfOutput.idl
// generated code does not contain a copyright notice

#ifndef ROS2KDB__MSG__DETAIL__EDF_OUTPUT__STRUCT_H_
#define ROS2KDB__MSG__DETAIL__EDF_OUTPUT__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Struct defined in msg/EdfOutput in the package ros2kdb.
typedef struct ros2kdb__msg__EdfOutput
{
  double speed;
} ros2kdb__msg__EdfOutput;

// Struct for a sequence of ros2kdb__msg__EdfOutput.
typedef struct ros2kdb__msg__EdfOutput__Sequence
{
  ros2kdb__msg__EdfOutput * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ros2kdb__msg__EdfOutput__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ROS2KDB__MSG__DETAIL__EDF_OUTPUT__STRUCT_H_
