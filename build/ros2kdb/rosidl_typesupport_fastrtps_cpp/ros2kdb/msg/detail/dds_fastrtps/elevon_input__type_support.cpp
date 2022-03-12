// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from ros2kdb:msg/ElevonInput.idl
// generated code does not contain a copyright notice
#include "ros2kdb/msg/detail/elevon_input__rosidl_typesupport_fastrtps_cpp.hpp"
#include "ros2kdb/msg/detail/elevon_input__struct.hpp"

#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions

namespace ros2kdb
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_ros2kdb
cdr_serialize(
  const ros2kdb::msg::ElevonInput & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: l_spd
  cdr << ros_message.l_spd;
  // Member: r_spd
  cdr << ros_message.r_spd;
  // Member: l_pos
  cdr << ros_message.l_pos;
  // Member: r_pos
  cdr << ros_message.r_pos;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_ros2kdb
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  ros2kdb::msg::ElevonInput & ros_message)
{
  // Member: l_spd
  cdr >> ros_message.l_spd;

  // Member: r_spd
  cdr >> ros_message.r_spd;

  // Member: l_pos
  cdr >> ros_message.l_pos;

  // Member: r_pos
  cdr >> ros_message.r_pos;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_ros2kdb
get_serialized_size(
  const ros2kdb::msg::ElevonInput & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: l_spd
  {
    size_t item_size = sizeof(ros_message.l_spd);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: r_spd
  {
    size_t item_size = sizeof(ros_message.r_spd);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: l_pos
  {
    size_t item_size = sizeof(ros_message.l_pos);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: r_pos
  {
    size_t item_size = sizeof(ros_message.r_pos);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_ros2kdb
max_serialized_size_ElevonInput(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;


  // Member: l_spd
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: r_spd
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: l_pos
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: r_pos
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  return current_alignment - initial_alignment;
}

static bool _ElevonInput__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const ros2kdb::msg::ElevonInput *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _ElevonInput__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<ros2kdb::msg::ElevonInput *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _ElevonInput__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const ros2kdb::msg::ElevonInput *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _ElevonInput__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_ElevonInput(full_bounded, 0);
}

static message_type_support_callbacks_t _ElevonInput__callbacks = {
  "ros2kdb::msg",
  "ElevonInput",
  _ElevonInput__cdr_serialize,
  _ElevonInput__cdr_deserialize,
  _ElevonInput__get_serialized_size,
  _ElevonInput__max_serialized_size
};

static rosidl_message_type_support_t _ElevonInput__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_ElevonInput__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace ros2kdb

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_ros2kdb
const rosidl_message_type_support_t *
get_message_type_support_handle<ros2kdb::msg::ElevonInput>()
{
  return &ros2kdb::msg::typesupport_fastrtps_cpp::_ElevonInput__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, ros2kdb, msg, ElevonInput)() {
  return &ros2kdb::msg::typesupport_fastrtps_cpp::_ElevonInput__handle;
}

#ifdef __cplusplus
}
#endif
