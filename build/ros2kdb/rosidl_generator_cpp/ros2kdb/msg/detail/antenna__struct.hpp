// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from ros2kdb:msg/Antenna.idl
// generated code does not contain a copyright notice

#ifndef ROS2KDB__MSG__DETAIL__ANTENNA__STRUCT_HPP_
#define ROS2KDB__MSG__DETAIL__ANTENNA__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__ros2kdb__msg__Antenna __attribute__((deprecated))
#else
# define DEPRECATED__ros2kdb__msg__Antenna __declspec(deprecated)
#endif

namespace ros2kdb
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Antenna_
{
  using Type = Antenna_<ContainerAllocator>;

  explicit Antenna_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->data = "";
    }
  }

  explicit Antenna_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : data(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->data = "";
    }
  }

  // field types and members
  using _data_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _data_type data;

  // setters for named parameter idiom
  Type & set__data(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->data = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    ros2kdb::msg::Antenna_<ContainerAllocator> *;
  using ConstRawPtr =
    const ros2kdb::msg::Antenna_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<ros2kdb::msg::Antenna_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<ros2kdb::msg::Antenna_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      ros2kdb::msg::Antenna_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<ros2kdb::msg::Antenna_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      ros2kdb::msg::Antenna_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<ros2kdb::msg::Antenna_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<ros2kdb::msg::Antenna_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<ros2kdb::msg::Antenna_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__ros2kdb__msg__Antenna
    std::shared_ptr<ros2kdb::msg::Antenna_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__ros2kdb__msg__Antenna
    std::shared_ptr<ros2kdb::msg::Antenna_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Antenna_ & other) const
  {
    if (this->data != other.data) {
      return false;
    }
    return true;
  }
  bool operator!=(const Antenna_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Antenna_

// alias to use template instance with default allocator
using Antenna =
  ros2kdb::msg::Antenna_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace ros2kdb

#endif  // ROS2KDB__MSG__DETAIL__ANTENNA__STRUCT_HPP_
