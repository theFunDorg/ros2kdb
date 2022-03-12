// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from ros2kdb:msg/ExhaustInput.idl
// generated code does not contain a copyright notice
#include "ros2kdb/msg/detail/exhaust_input__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


bool
ros2kdb__msg__ExhaustInput__init(ros2kdb__msg__ExhaustInput * msg)
{
  if (!msg) {
    return false;
  }
  // tl_spd
  // tr_spd
  // bl_spd
  // br_spd
  // tl_pos
  // tr_pos
  // bl_pos
  // br_pos
  return true;
}

void
ros2kdb__msg__ExhaustInput__fini(ros2kdb__msg__ExhaustInput * msg)
{
  if (!msg) {
    return;
  }
  // tl_spd
  // tr_spd
  // bl_spd
  // br_spd
  // tl_pos
  // tr_pos
  // bl_pos
  // br_pos
}

ros2kdb__msg__ExhaustInput *
ros2kdb__msg__ExhaustInput__create()
{
  ros2kdb__msg__ExhaustInput * msg = (ros2kdb__msg__ExhaustInput *)malloc(sizeof(ros2kdb__msg__ExhaustInput));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(ros2kdb__msg__ExhaustInput));
  bool success = ros2kdb__msg__ExhaustInput__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
ros2kdb__msg__ExhaustInput__destroy(ros2kdb__msg__ExhaustInput * msg)
{
  if (msg) {
    ros2kdb__msg__ExhaustInput__fini(msg);
  }
  free(msg);
}


bool
ros2kdb__msg__ExhaustInput__Sequence__init(ros2kdb__msg__ExhaustInput__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  ros2kdb__msg__ExhaustInput * data = NULL;
  if (size) {
    data = (ros2kdb__msg__ExhaustInput *)calloc(size, sizeof(ros2kdb__msg__ExhaustInput));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = ros2kdb__msg__ExhaustInput__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        ros2kdb__msg__ExhaustInput__fini(&data[i - 1]);
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
ros2kdb__msg__ExhaustInput__Sequence__fini(ros2kdb__msg__ExhaustInput__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      ros2kdb__msg__ExhaustInput__fini(&array->data[i]);
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

ros2kdb__msg__ExhaustInput__Sequence *
ros2kdb__msg__ExhaustInput__Sequence__create(size_t size)
{
  ros2kdb__msg__ExhaustInput__Sequence * array = (ros2kdb__msg__ExhaustInput__Sequence *)malloc(sizeof(ros2kdb__msg__ExhaustInput__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = ros2kdb__msg__ExhaustInput__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
ros2kdb__msg__ExhaustInput__Sequence__destroy(ros2kdb__msg__ExhaustInput__Sequence * array)
{
  if (array) {
    ros2kdb__msg__ExhaustInput__Sequence__fini(array);
  }
  free(array);
}
