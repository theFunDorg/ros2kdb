// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from ros2kdb:msg/Locate.idl
// generated code does not contain a copyright notice

#ifndef ROS2KDB__MSG__DETAIL__LOCATE__BUILDER_HPP_
#define ROS2KDB__MSG__DETAIL__LOCATE__BUILDER_HPP_

#include "ros2kdb/msg/detail/locate__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace ros2kdb
{

namespace msg
{

namespace builder
{

class Init_Locate_dist
{
public:
  explicit Init_Locate_dist(::ros2kdb::msg::Locate & msg)
  : msg_(msg)
  {}
  ::ros2kdb::msg::Locate dist(::ros2kdb::msg::Locate::_dist_type arg)
  {
    msg_.dist = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ros2kdb::msg::Locate msg_;
};

class Init_Locate_az
{
public:
  explicit Init_Locate_az(::ros2kdb::msg::Locate & msg)
  : msg_(msg)
  {}
  Init_Locate_dist az(::ros2kdb::msg::Locate::_az_type arg)
  {
    msg_.az = std::move(arg);
    return Init_Locate_dist(msg_);
  }

private:
  ::ros2kdb::msg::Locate msg_;
};

class Init_Locate_ay
{
public:
  explicit Init_Locate_ay(::ros2kdb::msg::Locate & msg)
  : msg_(msg)
  {}
  Init_Locate_az ay(::ros2kdb::msg::Locate::_ay_type arg)
  {
    msg_.ay = std::move(arg);
    return Init_Locate_az(msg_);
  }

private:
  ::ros2kdb::msg::Locate msg_;
};

class Init_Locate_ax
{
public:
  explicit Init_Locate_ax(::ros2kdb::msg::Locate & msg)
  : msg_(msg)
  {}
  Init_Locate_ay ax(::ros2kdb::msg::Locate::_ax_type arg)
  {
    msg_.ax = std::move(arg);
    return Init_Locate_ay(msg_);
  }

private:
  ::ros2kdb::msg::Locate msg_;
};

class Init_Locate_gz
{
public:
  explicit Init_Locate_gz(::ros2kdb::msg::Locate & msg)
  : msg_(msg)
  {}
  Init_Locate_ax gz(::ros2kdb::msg::Locate::_gz_type arg)
  {
    msg_.gz = std::move(arg);
    return Init_Locate_ax(msg_);
  }

private:
  ::ros2kdb::msg::Locate msg_;
};

class Init_Locate_gy
{
public:
  explicit Init_Locate_gy(::ros2kdb::msg::Locate & msg)
  : msg_(msg)
  {}
  Init_Locate_gz gy(::ros2kdb::msg::Locate::_gy_type arg)
  {
    msg_.gy = std::move(arg);
    return Init_Locate_gz(msg_);
  }

private:
  ::ros2kdb::msg::Locate msg_;
};

class Init_Locate_gx
{
public:
  Init_Locate_gx()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Locate_gy gx(::ros2kdb::msg::Locate::_gx_type arg)
  {
    msg_.gx = std::move(arg);
    return Init_Locate_gy(msg_);
  }

private:
  ::ros2kdb::msg::Locate msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::ros2kdb::msg::Locate>()
{
  return ros2kdb::msg::builder::Init_Locate_gx();
}

}  // namespace ros2kdb

#endif  // ROS2KDB__MSG__DETAIL__LOCATE__BUILDER_HPP_
