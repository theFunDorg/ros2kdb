// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from ros2kdb:msg/ExhaustOutput.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "ros2kdb/msg/detail/exhaust_output__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace ros2kdb
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void ExhaustOutput_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) ros2kdb::msg::ExhaustOutput(_init);
}

void ExhaustOutput_fini_function(void * message_memory)
{
  auto typed_message = static_cast<ros2kdb::msg::ExhaustOutput *>(message_memory);
  typed_message->~ExhaustOutput();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember ExhaustOutput_message_member_array[4] = {
  {
    "tl_pos",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ros2kdb::msg::ExhaustOutput, tl_pos),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "tr_pos",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ros2kdb::msg::ExhaustOutput, tr_pos),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "bl_pos",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ros2kdb::msg::ExhaustOutput, bl_pos),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "br_pos",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ros2kdb::msg::ExhaustOutput, br_pos),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers ExhaustOutput_message_members = {
  "ros2kdb::msg",  // message namespace
  "ExhaustOutput",  // message name
  4,  // number of fields
  sizeof(ros2kdb::msg::ExhaustOutput),
  ExhaustOutput_message_member_array,  // message members
  ExhaustOutput_init_function,  // function to initialize message memory (memory has to be allocated)
  ExhaustOutput_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t ExhaustOutput_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &ExhaustOutput_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace ros2kdb


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<ros2kdb::msg::ExhaustOutput>()
{
  return &::ros2kdb::msg::rosidl_typesupport_introspection_cpp::ExhaustOutput_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, ros2kdb, msg, ExhaustOutput)() {
  return &::ros2kdb::msg::rosidl_typesupport_introspection_cpp::ExhaustOutput_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
