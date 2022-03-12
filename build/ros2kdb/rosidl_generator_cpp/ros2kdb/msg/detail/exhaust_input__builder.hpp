// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from ros2kdb:msg/ExhaustInput.idl
// generated code does not contain a copyright notice

#ifndef ROS2KDB__MSG__DETAIL__EXHAUST_INPUT__BUILDER_HPP_
#define ROS2KDB__MSG__DETAIL__EXHAUST_INPUT__BUILDER_HPP_

#include "ros2kdb/msg/detail/exhaust_input__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace ros2kdb
{

namespace msg
{

namespace builder
{

class Init_ExhaustInput_br_pos
{
public:
  explicit Init_ExhaustInput_br_pos(::ros2kdb::msg::ExhaustInput & msg)
  : msg_(msg)
  {}
  ::ros2kdb::msg::ExhaustInput br_pos(::ros2kdb::msg::ExhaustInput::_br_pos_type arg)
  {
    msg_.br_pos = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ros2kdb::msg::ExhaustInput msg_;
};

class Init_ExhaustInput_bl_pos
{
public:
  explicit Init_ExhaustInput_bl_pos(::ros2kdb::msg::ExhaustInput & msg)
  : msg_(msg)
  {}
  Init_ExhaustInput_br_pos bl_pos(::ros2kdb::msg::ExhaustInput::_bl_pos_type arg)
  {
    msg_.bl_pos = std::move(arg);
    return Init_ExhaustInput_br_pos(msg_);
  }

private:
  ::ros2kdb::msg::ExhaustInput msg_;
};

class Init_ExhaustInput_tr_pos
{
public:
  explicit Init_ExhaustInput_tr_pos(::ros2kdb::msg::ExhaustInput & msg)
  : msg_(msg)
  {}
  Init_ExhaustInput_bl_pos tr_pos(::ros2kdb::msg::ExhaustInput::_tr_pos_type arg)
  {
    msg_.tr_pos = std::move(arg);
    return Init_ExhaustInput_bl_pos(msg_);
  }

private:
  ::ros2kdb::msg::ExhaustInput msg_;
};

class Init_ExhaustInput_tl_pos
{
public:
  explicit Init_ExhaustInput_tl_pos(::ros2kdb::msg::ExhaustInput & msg)
  : msg_(msg)
  {}
  Init_ExhaustInput_tr_pos tl_pos(::ros2kdb::msg::ExhaustInput::_tl_pos_type arg)
  {
    msg_.tl_pos = std::move(arg);
    return Init_ExhaustInput_tr_pos(msg_);
  }

private:
  ::ros2kdb::msg::ExhaustInput msg_;
};

class Init_ExhaustInput_br_spd
{
public:
  explicit Init_ExhaustInput_br_spd(::ros2kdb::msg::ExhaustInput & msg)
  : msg_(msg)
  {}
  Init_ExhaustInput_tl_pos br_spd(::ros2kdb::msg::ExhaustInput::_br_spd_type arg)
  {
    msg_.br_spd = std::move(arg);
    return Init_ExhaustInput_tl_pos(msg_);
  }

private:
  ::ros2kdb::msg::ExhaustInput msg_;
};

class Init_ExhaustInput_bl_spd
{
public:
  explicit Init_ExhaustInput_bl_spd(::ros2kdb::msg::ExhaustInput & msg)
  : msg_(msg)
  {}
  Init_ExhaustInput_br_spd bl_spd(::ros2kdb::msg::ExhaustInput::_bl_spd_type arg)
  {
    msg_.bl_spd = std::move(arg);
    return Init_ExhaustInput_br_spd(msg_);
  }

private:
  ::ros2kdb::msg::ExhaustInput msg_;
};

class Init_ExhaustInput_tr_spd
{
public:
  explicit Init_ExhaustInput_tr_spd(::ros2kdb::msg::ExhaustInput & msg)
  : msg_(msg)
  {}
  Init_ExhaustInput_bl_spd tr_spd(::ros2kdb::msg::ExhaustInput::_tr_spd_type arg)
  {
    msg_.tr_spd = std::move(arg);
    return Init_ExhaustInput_bl_spd(msg_);
  }

private:
  ::ros2kdb::msg::ExhaustInput msg_;
};

class Init_ExhaustInput_tl_spd
{
public:
  Init_ExhaustInput_tl_spd()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ExhaustInput_tr_spd tl_spd(::ros2kdb::msg::ExhaustInput::_tl_spd_type arg)
  {
    msg_.tl_spd = std::move(arg);
    return Init_ExhaustInput_tr_spd(msg_);
  }

private:
  ::ros2kdb::msg::ExhaustInput msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::ros2kdb::msg::ExhaustInput>()
{
  return ros2kdb::msg::builder::Init_ExhaustInput_tl_spd();
}

}  // namespace ros2kdb

#endif  // ROS2KDB__MSG__DETAIL__EXHAUST_INPUT__BUILDER_HPP_
