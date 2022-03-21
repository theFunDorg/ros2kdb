// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from ros2kdb:msg/ExhaustOutput.idl
// generated code does not contain a copyright notice

#ifndef ROS2KDB__MSG__DETAIL__EXHAUST_OUTPUT__STRUCT_HPP_
#define ROS2KDB__MSG__DETAIL__EXHAUST_OUTPUT__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__ros2kdb__msg__ExhaustOutput __attribute__((deprecated))
#else
# define DEPRECATED__ros2kdb__msg__ExhaustOutput __declspec(deprecated)
#endif

namespace ros2kdb
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct ExhaustOutput_
{
  using Type = ExhaustOutput_<ContainerAllocator>;

  explicit ExhaustOutput_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->tl_pos = 0.0;
      this->tr_pos = 0.0;
      this->bl_pos = 0.0;
      this->br_pos = 0.0;
    }
  }

  explicit ExhaustOutput_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->tl_pos = 0.0;
      this->tr_pos = 0.0;
      this->bl_pos = 0.0;
      this->br_pos = 0.0;
    }
  }

  // field types and members
  using _tl_pos_type =
    double;
  _tl_pos_type tl_pos;
  using _tr_pos_type =
    double;
  _tr_pos_type tr_pos;
  using _bl_pos_type =
    double;
  _bl_pos_type bl_pos;
  using _br_pos_type =
    double;
  _br_pos_type br_pos;

  // setters for named parameter idiom
  Type & set__tl_pos(
    const double & _arg)
  {
    this->tl_pos = _arg;
    return *this;
  }
  Type & set__tr_pos(
    const double & _arg)
  {
    this->tr_pos = _arg;
    return *this;
  }
  Type & set__bl_pos(
    const double & _arg)
  {
    this->bl_pos = _arg;
    return *this;
  }
  Type & set__br_pos(
    const double & _arg)
  {
    this->br_pos = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    ros2kdb::msg::ExhaustOutput_<ContainerAllocator> *;
  using ConstRawPtr =
    const ros2kdb::msg::ExhaustOutput_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<ros2kdb::msg::ExhaustOutput_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<ros2kdb::msg::ExhaustOutput_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      ros2kdb::msg::ExhaustOutput_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<ros2kdb::msg::ExhaustOutput_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      ros2kdb::msg::ExhaustOutput_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<ros2kdb::msg::ExhaustOutput_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<ros2kdb::msg::ExhaustOutput_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<ros2kdb::msg::ExhaustOutput_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__ros2kdb__msg__ExhaustOutput
    std::shared_ptr<ros2kdb::msg::ExhaustOutput_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__ros2kdb__msg__ExhaustOutput
    std::shared_ptr<ros2kdb::msg::ExhaustOutput_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ExhaustOutput_ & other) const
  {
    if (this->tl_pos != other.tl_pos) {
      return false;
    }
    if (this->tr_pos != other.tr_pos) {
      return false;
    }
    if (this->bl_pos != other.bl_pos) {
      return false;
    }
    if (this->br_pos != other.br_pos) {
      return false;
    }
    return true;
  }
  bool operator!=(const ExhaustOutput_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ExhaustOutput_

// alias to use template instance with default allocator
using ExhaustOutput =
  ros2kdb::msg::ExhaustOutput_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace ros2kdb

#endif  // ROS2KDB__MSG__DETAIL__EXHAUST_OUTPUT__STRUCT_HPP_