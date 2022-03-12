// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from ros2kdb:msg/EdfInput.idl
// generated code does not contain a copyright notice

#ifndef ROS2KDB__MSG__DETAIL__EDF_INPUT__STRUCT_HPP_
#define ROS2KDB__MSG__DETAIL__EDF_INPUT__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__ros2kdb__msg__EdfInput __attribute__((deprecated))
#else
# define DEPRECATED__ros2kdb__msg__EdfInput __declspec(deprecated)
#endif

namespace ros2kdb
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct EdfInput_
{
  using Type = EdfInput_<ContainerAllocator>;

  explicit EdfInput_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->speed = 0.0;
    }
  }

  explicit EdfInput_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->speed = 0.0;
    }
  }

  // field types and members
  using _speed_type =
    double;
  _speed_type speed;

  // setters for named parameter idiom
  Type & set__speed(
    const double & _arg)
  {
    this->speed = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    ros2kdb::msg::EdfInput_<ContainerAllocator> *;
  using ConstRawPtr =
    const ros2kdb::msg::EdfInput_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<ros2kdb::msg::EdfInput_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<ros2kdb::msg::EdfInput_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      ros2kdb::msg::EdfInput_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<ros2kdb::msg::EdfInput_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      ros2kdb::msg::EdfInput_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<ros2kdb::msg::EdfInput_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<ros2kdb::msg::EdfInput_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<ros2kdb::msg::EdfInput_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__ros2kdb__msg__EdfInput
    std::shared_ptr<ros2kdb::msg::EdfInput_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__ros2kdb__msg__EdfInput
    std::shared_ptr<ros2kdb::msg::EdfInput_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const EdfInput_ & other) const
  {
    if (this->speed != other.speed) {
      return false;
    }
    return true;
  }
  bool operator!=(const EdfInput_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct EdfInput_

// alias to use template instance with default allocator
using EdfInput =
  ros2kdb::msg::EdfInput_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace ros2kdb

#endif  // ROS2KDB__MSG__DETAIL__EDF_INPUT__STRUCT_HPP_
