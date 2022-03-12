// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from ros2kdb:msg/ElevonInput.idl
// generated code does not contain a copyright notice

#ifndef ROS2KDB__MSG__DETAIL__ELEVON_INPUT__BUILDER_HPP_
#define ROS2KDB__MSG__DETAIL__ELEVON_INPUT__BUILDER_HPP_

#include "ros2kdb/msg/detail/elevon_input__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace ros2kdb
{

namespace msg
{

namespace builder
{

class Init_ElevonInput_r_pos
{
public:
  explicit Init_ElevonInput_r_pos(::ros2kdb::msg::ElevonInput & msg)
  : msg_(msg)
  {}
  ::ros2kdb::msg::ElevonInput r_pos(::ros2kdb::msg::ElevonInput::_r_pos_type arg)
  {
    msg_.r_pos = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ros2kdb::msg::ElevonInput msg_;
};

class Init_ElevonInput_l_pos
{
public:
  explicit Init_ElevonInput_l_pos(::ros2kdb::msg::ElevonInput & msg)
  : msg_(msg)
  {}
  Init_ElevonInput_r_pos l_pos(::ros2kdb::msg::ElevonInput::_l_pos_type arg)
  {
    msg_.l_pos = std::move(arg);
    return Init_ElevonInput_r_pos(msg_);
  }

private:
  ::ros2kdb::msg::ElevonInput msg_;
};

class Init_ElevonInput_r_spd
{
public:
  explicit Init_ElevonInput_r_spd(::ros2kdb::msg::ElevonInput & msg)
  : msg_(msg)
  {}
  Init_ElevonInput_l_pos r_spd(::ros2kdb::msg::ElevonInput::_r_spd_type arg)
  {
    msg_.r_spd = std::move(arg);
    return Init_ElevonInput_l_pos(msg_);
  }

private:
  ::ros2kdb::msg::ElevonInput msg_;
};

class Init_ElevonInput_l_spd
{
public:
  Init_ElevonInput_l_spd()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ElevonInput_r_spd l_spd(::ros2kdb::msg::ElevonInput::_l_spd_type arg)
  {
    msg_.l_spd = std::move(arg);
    return Init_ElevonInput_r_spd(msg_);
  }

private:
  ::ros2kdb::msg::ElevonInput msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::ros2kdb::msg::ElevonInput>()
{
  return ros2kdb::msg::builder::Init_ElevonInput_l_spd();
}

}  // namespace ros2kdb

#endif  // ROS2KDB__MSG__DETAIL__ELEVON_INPUT__BUILDER_HPP_
