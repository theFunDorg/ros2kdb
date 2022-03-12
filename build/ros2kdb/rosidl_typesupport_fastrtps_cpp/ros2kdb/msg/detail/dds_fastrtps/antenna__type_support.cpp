// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from ros2kdb:msg/Antenna.idl
// generated code does not contain a copyright notice
#include "ros2kdb/msg/detail/antenna__rosidl_typesupport_fastrtps_cpp.hpp"
#include "ros2kdb/msg/detail/antenna__struct.hpp"

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
  const ros2kdb::msg::Antenna & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: data
  cdr << ros_message.data;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_ros2kdb
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  ros2kdb::msg::Antenna & ros_message)
{
  // Member: data
  cdr >> ros_message.data;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_ros2kdb
get_serialized_size(
  const ros2kdb::msg::Antenna & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: data
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.data.size() + 1);

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_ros2kdb
max_serialized_size_Antenna(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;


  // Member: data
  {
    size_t array_size = 1;

    full_bounded = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  return current_alignment - initial_alignment;
}

static bool _Antenna__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const ros2kdb::msg::Antenna *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _Antenna__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<ros2kdb::msg::Antenna *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _Antenna__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const ros2kdb::msg::Antenna *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _Antenna__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_Antenna(full_bounded, 0);
}

static message_type_support_callbacks_t _Antenna__callbacks = {
  "ros2kdb::msg",
  "Antenna",
  _Antenna__cdr_serialize,
  _Antenna__cdr_deserialize,
  _Antenna__get_serialized_size,
  _Antenna__max_serialized_size
};

static rosidl_message_type_support_t _Antenna__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_Antenna__callbacks,
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
get_message_type_support_handle<ros2kdb::msg::Antenna>()
{
  return &ros2kdb::msg::typesupport_fastrtps_cpp::_Antenna__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, ros2kdb, msg, Antenna)() {
  return &ros2kdb::msg::typesupport_fastrtps_cpp::_Antenna__handle;
}

#ifdef __cplusplus
}
#endif
