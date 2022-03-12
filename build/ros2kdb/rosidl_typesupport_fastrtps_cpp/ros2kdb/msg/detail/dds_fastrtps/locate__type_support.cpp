// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from ros2kdb:msg/Locate.idl
// generated code does not contain a copyright notice
#include "ros2kdb/msg/detail/locate__rosidl_typesupport_fastrtps_cpp.hpp"
#include "ros2kdb/msg/detail/locate__struct.hpp"

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
  const ros2kdb::msg::Locate & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: gx
  cdr << ros_message.gx;
  // Member: gy
  cdr << ros_message.gy;
  // Member: gz
  cdr << ros_message.gz;
  // Member: ax
  cdr << ros_message.ax;
  // Member: ay
  cdr << ros_message.ay;
  // Member: az
  cdr << ros_message.az;
  // Member: dist
  cdr << ros_message.dist;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_ros2kdb
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  ros2kdb::msg::Locate & ros_message)
{
  // Member: gx
  cdr >> ros_message.gx;

  // Member: gy
  cdr >> ros_message.gy;

  // Member: gz
  cdr >> ros_message.gz;

  // Member: ax
  cdr >> ros_message.ax;

  // Member: ay
  cdr >> ros_message.ay;

  // Member: az
  cdr >> ros_message.az;

  // Member: dist
  cdr >> ros_message.dist;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_ros2kdb
get_serialized_size(
  const ros2kdb::msg::Locate & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: gx
  {
    size_t item_size = sizeof(ros_message.gx);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: gy
  {
    size_t item_size = sizeof(ros_message.gy);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: gz
  {
    size_t item_size = sizeof(ros_message.gz);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: ax
  {
    size_t item_size = sizeof(ros_message.ax);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: ay
  {
    size_t item_size = sizeof(ros_message.ay);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: az
  {
    size_t item_size = sizeof(ros_message.az);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: dist
  {
    size_t item_size = sizeof(ros_message.dist);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_ros2kdb
max_serialized_size_Locate(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;


  // Member: gx
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: gy
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: gz
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: ax
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: ay
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: az
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: dist
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  return current_alignment - initial_alignment;
}

static bool _Locate__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const ros2kdb::msg::Locate *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _Locate__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<ros2kdb::msg::Locate *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _Locate__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const ros2kdb::msg::Locate *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _Locate__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_Locate(full_bounded, 0);
}

static message_type_support_callbacks_t _Locate__callbacks = {
  "ros2kdb::msg",
  "Locate",
  _Locate__cdr_serialize,
  _Locate__cdr_deserialize,
  _Locate__get_serialized_size,
  _Locate__max_serialized_size
};

static rosidl_message_type_support_t _Locate__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_Locate__callbacks,
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
get_message_type_support_handle<ros2kdb::msg::Locate>()
{
  return &ros2kdb::msg::typesupport_fastrtps_cpp::_Locate__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, ros2kdb, msg, Locate)() {
  return &ros2kdb::msg::typesupport_fastrtps_cpp::_Locate__handle;
}

#ifdef __cplusplus
}
#endif
