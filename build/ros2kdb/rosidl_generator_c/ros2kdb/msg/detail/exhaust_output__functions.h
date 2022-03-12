// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from ros2kdb:msg/ExhaustOutput.idl
// generated code does not contain a copyright notice

#ifndef ROS2KDB__MSG__DETAIL__EXHAUST_OUTPUT__FUNCTIONS_H_
#define ROS2KDB__MSG__DETAIL__EXHAUST_OUTPUT__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "ros2kdb/msg/rosidl_generator_c__visibility_control.h"

#include "ros2kdb/msg/detail/exhaust_output__struct.h"

/// Initialize msg/ExhaustOutput message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * ros2kdb__msg__ExhaustOutput
 * )) before or use
 * ros2kdb__msg__ExhaustOutput__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_ros2kdb
bool
ros2kdb__msg__ExhaustOutput__init(ros2kdb__msg__ExhaustOutput * msg);

/// Finalize msg/ExhaustOutput message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_ros2kdb
void
ros2kdb__msg__ExhaustOutput__fini(ros2kdb__msg__ExhaustOutput * msg);

/// Create msg/ExhaustOutput message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * ros2kdb__msg__ExhaustOutput__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_ros2kdb
ros2kdb__msg__ExhaustOutput *
ros2kdb__msg__ExhaustOutput__create();

/// Destroy msg/ExhaustOutput message.
/**
 * It calls
 * ros2kdb__msg__ExhaustOutput__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_ros2kdb
void
ros2kdb__msg__ExhaustOutput__destroy(ros2kdb__msg__ExhaustOutput * msg);


/// Initialize array of msg/ExhaustOutput messages.
/**
 * It allocates the memory for the number of elements and calls
 * ros2kdb__msg__ExhaustOutput__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_ros2kdb
bool
ros2kdb__msg__ExhaustOutput__Sequence__init(ros2kdb__msg__ExhaustOutput__Sequence * array, size_t size);

/// Finalize array of msg/ExhaustOutput messages.
/**
 * It calls
 * ros2kdb__msg__ExhaustOutput__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_ros2kdb
void
ros2kdb__msg__ExhaustOutput__Sequence__fini(ros2kdb__msg__ExhaustOutput__Sequence * array);

/// Create array of msg/ExhaustOutput messages.
/**
 * It allocates the memory for the array and calls
 * ros2kdb__msg__ExhaustOutput__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_ros2kdb
ros2kdb__msg__ExhaustOutput__Sequence *
ros2kdb__msg__ExhaustOutput__Sequence__create(size_t size);

/// Destroy array of msg/ExhaustOutput messages.
/**
 * It calls
 * ros2kdb__msg__ExhaustOutput__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_ros2kdb
void
ros2kdb__msg__ExhaustOutput__Sequence__destroy(ros2kdb__msg__ExhaustOutput__Sequence * array);

#ifdef __cplusplus
}
#endif

#endif  // ROS2KDB__MSG__DETAIL__EXHAUST_OUTPUT__FUNCTIONS_H_
