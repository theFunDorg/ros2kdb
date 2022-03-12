// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from ros2kdb:msg/Locate.idl
// generated code does not contain a copyright notice

#ifndef ROS2KDB__MSG__DETAIL__LOCATE__STRUCT_H_
#define ROS2KDB__MSG__DETAIL__LOCATE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Struct defined in msg/Locate in the package ros2kdb.
typedef struct ros2kdb__msg__Locate
{
  double gx;
  double gy;
  double gz;
  double ax;
  double ay;
  double az;
  double dist;
} ros2kdb__msg__Locate;

// Struct for a sequence of ros2kdb__msg__Locate.
typedef struct ros2kdb__msg__Locate__Sequence
{
  ros2kdb__msg__Locate * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ros2kdb__msg__Locate__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ROS2KDB__MSG__DETAIL__LOCATE__STRUCT_H_
