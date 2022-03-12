// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from ros2kdb:msg/Antenna.idl
// generated code does not contain a copyright notice
#include "ros2kdb/msg/detail/antenna__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


// Include directives for member types
// Member `data`
#include "rosidl_runtime_c/string_functions.h"

bool
ros2kdb__msg__Antenna__init(ros2kdb__msg__Antenna * msg)
{
  if (!msg) {
    return false;
  }
  // data
  if (!rosidl_runtime_c__String__init(&msg->data)) {
    ros2kdb__msg__Antenna__fini(msg);
    return false;
  }
  return true;
}

void
ros2kdb__msg__Antenna__fini(ros2kdb__msg__Antenna * msg)
{
  if (!msg) {
    return;
  }
  // data
  rosidl_runtime_c__String__fini(&msg->data);
}

ros2kdb__msg__Antenna *
ros2kdb__msg__Antenna__create()
{
  ros2kdb__msg__Antenna * msg = (ros2kdb__msg__Antenna *)malloc(sizeof(ros2kdb__msg__Antenna));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(ros2kdb__msg__Antenna));
  bool success = ros2kdb__msg__Antenna__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
ros2kdb__msg__Antenna__destroy(ros2kdb__msg__Antenna * msg)
{
  if (msg) {
    ros2kdb__msg__Antenna__fini(msg);
  }
  free(msg);
}


bool
ros2kdb__msg__Antenna__Sequence__init(ros2kdb__msg__Antenna__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  ros2kdb__msg__Antenna * data = NULL;
  if (size) {
    data = (ros2kdb__msg__Antenna *)calloc(size, sizeof(ros2kdb__msg__Antenna));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = ros2kdb__msg__Antenna__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        ros2kdb__msg__Antenna__fini(&data[i - 1]);
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
ros2kdb__msg__Antenna__Sequence__fini(ros2kdb__msg__Antenna__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      ros2kdb__msg__Antenna__fini(&array->data[i]);
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

ros2kdb__msg__Antenna__Sequence *
ros2kdb__msg__Antenna__Sequence__create(size_t size)
{
  ros2kdb__msg__Antenna__Sequence * array = (ros2kdb__msg__Antenna__Sequence *)malloc(sizeof(ros2kdb__msg__Antenna__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = ros2kdb__msg__Antenna__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
ros2kdb__msg__Antenna__Sequence__destroy(ros2kdb__msg__Antenna__Sequence * array)
{
  if (array) {
    ros2kdb__msg__Antenna__Sequence__fini(array);
  }
  free(array);
}
