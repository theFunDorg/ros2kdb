// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from ros2kdb:msg/ElevonInput.idl
// generated code does not contain a copyright notice
#include "ros2kdb/msg/detail/elevon_input__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


bool
ros2kdb__msg__ElevonInput__init(ros2kdb__msg__ElevonInput * msg)
{
  if (!msg) {
    return false;
  }
  // l_spd
  // r_spd
  // l_pos
  // r_pos
  return true;
}

void
ros2kdb__msg__ElevonInput__fini(ros2kdb__msg__ElevonInput * msg)
{
  if (!msg) {
    return;
  }
  // l_spd
  // r_spd
  // l_pos
  // r_pos
}

ros2kdb__msg__ElevonInput *
ros2kdb__msg__ElevonInput__create()
{
  ros2kdb__msg__ElevonInput * msg = (ros2kdb__msg__ElevonInput *)malloc(sizeof(ros2kdb__msg__ElevonInput));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(ros2kdb__msg__ElevonInput));
  bool success = ros2kdb__msg__ElevonInput__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
ros2kdb__msg__ElevonInput__destroy(ros2kdb__msg__ElevonInput * msg)
{
  if (msg) {
    ros2kdb__msg__ElevonInput__fini(msg);
  }
  free(msg);
}


bool
ros2kdb__msg__ElevonInput__Sequence__init(ros2kdb__msg__ElevonInput__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  ros2kdb__msg__ElevonInput * data = NULL;
  if (size) {
    data = (ros2kdb__msg__ElevonInput *)calloc(size, sizeof(ros2kdb__msg__ElevonInput));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = ros2kdb__msg__ElevonInput__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        ros2kdb__msg__ElevonInput__fini(&data[i - 1]);
      }
      free(data);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
ros2kdb__msg__ElevonInput__Sequence__fini(ros2kdb__msg__ElevonInput__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      ros2kdb__msg__ElevonInput__fini(&array->data[i]);
    }
    free(array->data);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

ros2kdb__msg__ElevonInput__Sequence *
ros2kdb__msg__ElevonInput__Sequence__create(size_t size)
{
  ros2kdb__msg__ElevonInput__Sequence * array = (ros2kdb__msg__ElevonInput__Sequence *)malloc(sizeof(ros2kdb__msg__ElevonInput__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = ros2kdb__msg__ElevonInput__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
ros2kdb__msg__ElevonInput__Sequence__destroy(ros2kdb__msg__ElevonInput__Sequence * array)
{
  if (array) {
    ros2kdb__msg__ElevonInput__Sequence__fini(array);
  }
  free(array);
}
