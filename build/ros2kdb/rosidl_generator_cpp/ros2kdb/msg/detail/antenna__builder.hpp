// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from ros2kdb:msg/Antenna.idl
// generated code does not contain a copyright notice

#ifndef ROS2KDB__MSG__DETAIL__ANTENNA__BUILDER_HPP_
#define ROS2KDB__MSG__DETAIL__ANTENNA__BUILDER_HPP_

#include "ros2kdb/msg/detail/antenna__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace ros2kdb
{

namespace msg
{

namespace builder
{

class Init_Antenna_data
{
public:
  Init_Antenna_data()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::ros2kdb::msg::Antenna data(::ros2kdb::msg::Antenna::_data_type arg)
  {
    msg_.data = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ros2kdb::msg::Antenna msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::ros2kdb::msg::Antenna>()
{
  return ros2kdb::msg::builder::Init_Antenna_data();
}

}  // namespace ros2kdb

#endif  // ROS2KDB__MSG__DETAIL__ANTENNA__BUILDER_HPP_
