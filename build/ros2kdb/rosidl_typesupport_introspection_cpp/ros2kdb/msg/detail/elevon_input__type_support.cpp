// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from ros2kdb:msg/ElevonInput.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "ros2kdb/msg/detail/elevon_input__struct.hpp"
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

void ElevonInput_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) ros2kdb::msg::ElevonInput(_init);
}

void ElevonInput_fini_function(void * message_memory)
{
  auto typed_message = static_cast<ros2kdb::msg::ElevonInput *>(message_memory);
  typed_message->~ElevonInput();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember ElevonInput_message_member_array[4] = {
  {
    "l_spd",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ros2kdb::msg::ElevonInput, l_spd),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "r_spd",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ros2kdb::msg::ElevonInput, r_spd),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "l_pos",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ros2kdb::msg::ElevonInput, l_pos),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "r_pos",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ros2kdb::msg::ElevonInput, r_pos),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers ElevonInput_message_members = {
  "ros2kdb::msg",  // message namespace
  "ElevonInput",  // message name
  4,  // number of fields
  sizeof(ros2kdb::msg::ElevonInput),
  ElevonInput_message_member_array,  // message members
  ElevonInput_init_function,  // function to initialize message memory (memory has to be allocated)
  ElevonInput_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t ElevonInput_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &ElevonInput_message_members,
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
get_message_type_support_handle<ros2kdb::msg::ElevonInput>()
{
  return &::ros2kdb::msg::rosidl_typesupport_introspection_cpp::ElevonInput_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, ros2kdb, msg, ElevonInput)() {
  return &::ros2kdb::msg::rosidl_typesupport_introspection_cpp::ElevonInput_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
