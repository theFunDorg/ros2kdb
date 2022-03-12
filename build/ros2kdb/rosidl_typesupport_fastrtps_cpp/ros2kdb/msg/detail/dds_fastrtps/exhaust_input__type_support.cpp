// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from ros2kdb:msg/ExhaustInput.idl
// generated code does not contain a copyright notice
#include "ros2kdb/msg/detail/exhaust_input__rosidl_typesupport_fastrtps_cpp.hpp"
#include "ros2kdb/msg/detail/exhaust_input__struct.hpp"

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
  const ros2kdb::msg::ExhaustInput & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: tl_spd
  cdr << ros_message.tl_spd;
  // Member: tr_spd
  cdr << ros_message.tr_spd;
  // Member: bl_spd
  cdr << ros_message.bl_spd;
  // Member: br_spd
  cdr << ros_message.br_spd;
  // Member: tl_pos
  cdr << ros_message.tl_pos;
  // Member: tr_pos
  cdr << ros_message.tr_pos;
  // Member: bl_pos
  cdr << ros_message.bl_pos;
  // Member: br_pos
  cdr << ros_message.br_pos;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_ros2kdb
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  ros2kdb::msg::ExhaustInput & ros_message)
{
  // Member: tl_spd
  cdr >> ros_message.tl_spd;

  // Member: tr_spd
  cdr >> ros_message.tr_spd;

  // Member: bl_spd
  cdr >> ros_message.bl_spd;

  // Member: br_spd
  cdr >> ros_message.br_spd;

  // Member: tl_pos
  cdr >> ros_message.tl_pos;

  // Member: tr_pos
  cdr >> ros_message.tr_pos;

  // Member: bl_pos
  cdr >> ros_message.bl_pos;

  // Member: br_pos
  cdr >> ros_message.br_pos;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_ros2kdb
get_serialized_size(
  const ros2kdb::msg::ExhaustInput & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: tl_spd
  {
    size_t item_size = sizeof(ros_message.tl_spd);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: tr_spd
  {
    size_t item_size = sizeof(ros_message.tr_spd);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: bl_spd
  {
    size_t item_size = sizeof(ros_message.bl_spd);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: br_spd
  {
    size_t item_size = sizeof(ros_message.br_spd);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: tl_pos
  {
    size_t item_size = sizeof(ros_message.tl_pos);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: tr_pos
  {
    size_t item_size = sizeof(ros_message.tr_pos);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: bl_pos
  {
    size_t item_size = sizeof(ros_message.bl_pos);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: br_pos
  {
    size_t item_size = sizeof(ros_message.br_pos);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_ros2kdb
max_serialized_size_ExhaustInput(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;


  // Member: tl_spd
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: tr_spd
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: bl_spd
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: br_spd
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: tl_pos
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: tr_pos
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: bl_pos
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: br_pos
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  return current_alignment - initial_alignment;
}

static bool _ExhaustInput__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const ros2kdb::msg::ExhaustInput *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _ExhaustInput__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<ros2kdb::msg::ExhaustInput *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _ExhaustInput__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const ros2kdb::msg::ExhaustInput *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _ExhaustInput__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_ExhaustInput(full_bounded, 0);
}

static message_type_support_callbacks_t _ExhaustInput__callbacks = {
  "ros2kdb::msg",
  "ExhaustInput",
  _ExhaustInput__cdr_serialize,
  _ExhaustInput__cdr_deserialize,
  _ExhaustInput__get_serialized_size,
  _ExhaustInput__max_serialized_size
};

static rosidl_message_type_support_t _ExhaustInput__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_ExhaustInput__callbacks,
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
get_message_type_support_handle<ros2kdb::msg::ExhaustInput>()
{
  return &ros2kdb::msg::typesupport_fastrtps_cpp::_ExhaustInput__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, ros2kdb, msg, ExhaustInput)() {
  return &ros2kdb::msg::typesupport_fastrtps_cpp::_ExhaustInput__handle;
}

#ifdef __cplusplus
}
#endif
