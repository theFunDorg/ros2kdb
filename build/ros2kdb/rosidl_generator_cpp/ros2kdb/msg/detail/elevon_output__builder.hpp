// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from ros2kdb:msg/ElevonOutput.idl
// generated code does not contain a copyright notice

#ifndef ROS2KDB__MSG__DETAIL__ELEVON_OUTPUT__BUILDER_HPP_
#define ROS2KDB__MSG__DETAIL__ELEVON_OUTPUT__BUILDER_HPP_

#include "ros2kdb/msg/detail/elevon_output__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace ros2kdb
{

namespace msg
{

namespace builder
{

class Init_ElevonOutput_r_pos
{
public:
  explicit Init_ElevonOutput_r_pos(::ros2kdb::msg::ElevonOutput & msg)
  : msg_(msg)
  {}
  ::ros2kdb::msg::ElevonOutput r_pos(::ros2kdb::msg::ElevonOutput::_r_pos_type arg)
  {
    msg_.r_pos = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ros2kdb::msg::ElevonOutput msg_;
};

class Init_ElevonOutput_l_pos
{
public:
  Init_ElevonOutput_l_pos()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ElevonOutput_r_pos l_pos(::ros2kdb::msg::ElevonOutput::_l_pos_type arg)
  {
    msg_.l_pos = std::move(arg);
    return Init_ElevonOutput_r_pos(msg_);
  }

private:
  ::ros2kdb::msg::ElevonOutput msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::ros2kdb::msg::ElevonOutput>()
{
  return ros2kdb::msg::builder::Init_ElevonOutput_l_pos();
}

}  // namespace ros2kdb

#endif  // ROS2KDB__MSG__DETAIL__ELEVON_OUTPUT__BUILDER_HPP_
