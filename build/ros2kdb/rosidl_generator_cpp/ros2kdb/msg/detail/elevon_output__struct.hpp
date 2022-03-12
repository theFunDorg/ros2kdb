// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from ros2kdb:msg/ElevonOutput.idl
// generated code does not contain a copyright notice

#ifndef ROS2KDB__MSG__DETAIL__ELEVON_OUTPUT__STRUCT_HPP_
#define ROS2KDB__MSG__DETAIL__ELEVON_OUTPUT__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__ros2kdb__msg__ElevonOutput __attribute__((deprecated))
#else
# define DEPRECATED__ros2kdb__msg__ElevonOutput __declspec(deprecated)
#endif

namespace ros2kdb
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct ElevonOutput_
{
  using Type = ElevonOutput_<ContainerAllocator>;

  explicit ElevonOutput_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->l_pos = 0.0;
      this->r_pos = 0.0;
    }
  }

  explicit ElevonOutput_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->l_pos = 0.0;
      this->r_pos = 0.0;
    }
  }

  // field types and members
  using _l_pos_type =
    double;
  _l_pos_type l_pos;
  using _r_pos_type =
    double;
  _r_pos_type r_pos;

  // setters for named parameter idiom
  Type & set__l_pos(
    const double & _arg)
  {
    this->l_pos = _arg;
    return *this;
  }
  Type & set__r_pos(
    const double & _arg)
  {
    this->r_pos = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    ros2kdb::msg::ElevonOutput_<ContainerAllocator> *;
  using ConstRawPtr =
    const ros2kdb::msg::ElevonOutput_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<ros2kdb::msg::ElevonOutput_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<ros2kdb::msg::ElevonOutput_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      ros2kdb::msg::ElevonOutput_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<ros2kdb::msg::ElevonOutput_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      ros2kdb::msg::ElevonOutput_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<ros2kdb::msg::ElevonOutput_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<ros2kdb::msg::ElevonOutput_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<ros2kdb::msg::ElevonOutput_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__ros2kdb__msg__ElevonOutput
    std::shared_ptr<ros2kdb::msg::ElevonOutput_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__ros2kdb__msg__ElevonOutput
    std::shared_ptr<ros2kdb::msg::ElevonOutput_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ElevonOutput_ & other) const
  {
    if (this->l_pos != other.l_pos) {
      return false;
    }
    if (this->r_pos != other.r_pos) {
      return false;
    }
    return true;
  }
  bool operator!=(const ElevonOutput_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ElevonOutput_

// alias to use template instance with default allocator
using ElevonOutput =
  ros2kdb::msg::ElevonOutput_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace ros2kdb

#endif  // ROS2KDB__MSG__DETAIL__ELEVON_OUTPUT__STRUCT_HPP_
