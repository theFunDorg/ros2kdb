// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from ros2kdb:msg/EdfOutput.idl
// generated code does not contain a copyright notice

#ifndef ROS2KDB__MSG__DETAIL__EDF_OUTPUT__BUILDER_HPP_
#define ROS2KDB__MSG__DETAIL__EDF_OUTPUT__BUILDER_HPP_

#include "ros2kdb/msg/detail/edf_output__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace ros2kdb
{

namespace msg
{

namespace builder
{

class Init_EdfOutput_speed
{
public:
  Init_EdfOutput_speed()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::ros2kdb::msg::EdfOutput speed(::ros2kdb::msg::EdfOutput::_speed_type arg)
  {
    msg_.speed = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ros2kdb::msg::EdfOutput msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::ros2kdb::msg::EdfOutput>()
{
  return ros2kdb::msg::builder::Init_EdfOutput_speed();
}

}  // namespace ros2kdb

#endif  // ROS2KDB__MSG__DETAIL__EDF_OUTPUT__BUILDER_HPP_
