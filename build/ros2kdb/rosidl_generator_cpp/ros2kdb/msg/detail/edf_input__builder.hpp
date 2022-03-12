// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from ros2kdb:msg/EdfInput.idl
// generated code does not contain a copyright notice

#ifndef ROS2KDB__MSG__DETAIL__EDF_INPUT__BUILDER_HPP_
#define ROS2KDB__MSG__DETAIL__EDF_INPUT__BUILDER_HPP_

#include "ros2kdb/msg/detail/edf_input__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace ros2kdb
{

namespace msg
{

namespace builder
{

class Init_EdfInput_speed
{
public:
  Init_EdfInput_speed()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::ros2kdb::msg::EdfInput speed(::ros2kdb::msg::EdfInput::_speed_type arg)
  {
    msg_.speed = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ros2kdb::msg::EdfInput msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::ros2kdb::msg::EdfInput>()
{
  return ros2kdb::msg::builder::Init_EdfInput_speed();
}

}  // namespace ros2kdb

#endif  // ROS2KDB__MSG__DETAIL__EDF_INPUT__BUILDER_HPP_
