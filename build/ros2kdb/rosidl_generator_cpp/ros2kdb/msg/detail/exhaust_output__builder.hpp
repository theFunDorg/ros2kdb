// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from ros2kdb:msg/ExhaustOutput.idl
// generated code does not contain a copyright notice

#ifndef ROS2KDB__MSG__DETAIL__EXHAUST_OUTPUT__BUILDER_HPP_
#define ROS2KDB__MSG__DETAIL__EXHAUST_OUTPUT__BUILDER_HPP_

#include "ros2kdb/msg/detail/exhaust_output__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace ros2kdb
{

namespace msg
{

namespace builder
{

class Init_ExhaustOutput_br_pos
{
public:
  explicit Init_ExhaustOutput_br_pos(::ros2kdb::msg::ExhaustOutput & msg)
  : msg_(msg)
  {}
  ::ros2kdb::msg::ExhaustOutput br_pos(::ros2kdb::msg::ExhaustOutput::_br_pos_type arg)
  {
    msg_.br_pos = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ros2kdb::msg::ExhaustOutput msg_;
};

class Init_ExhaustOutput_bl_pos
{
public:
  explicit Init_ExhaustOutput_bl_pos(::ros2kdb::msg::ExhaustOutput & msg)
  : msg_(msg)
  {}
  Init_ExhaustOutput_br_pos bl_pos(::ros2kdb::msg::ExhaustOutput::_bl_pos_type arg)
  {
    msg_.bl_pos = std::move(arg);
    return Init_ExhaustOutput_br_pos(msg_);
  }

private:
  ::ros2kdb::msg::ExhaustOutput msg_;
};

class Init_ExhaustOutput_tr_pos
{
public:
  explicit Init_ExhaustOutput_tr_pos(::ros2kdb::msg::ExhaustOutput & msg)
  : msg_(msg)
  {}
  Init_ExhaustOutput_bl_pos tr_pos(::ros2kdb::msg::ExhaustOutput::_tr_pos_type arg)
  {
    msg_.tr_pos = std::move(arg);
    return Init_ExhaustOutput_bl_pos(msg_);
  }

private:
  ::ros2kdb::msg::ExhaustOutput msg_;
};

class Init_ExhaustOutput_tl_pos
{
public:
  Init_ExhaustOutput_tl_pos()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ExhaustOutput_tr_pos tl_pos(::ros2kdb::msg::ExhaustOutput::_tl_pos_type arg)
  {
    msg_.tl_pos = std::move(arg);
    return Init_ExhaustOutput_tr_pos(msg_);
  }

private:
  ::ros2kdb::msg::ExhaustOutput msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::ros2kdb::msg::ExhaustOutput>()
{
  return ros2kdb::msg::builder::Init_ExhaustOutput_tl_pos();
}

}  // namespace ros2kdb

#endif  // ROS2KDB__MSG__DETAIL__EXHAUST_OUTPUT__BUILDER_HPP_
