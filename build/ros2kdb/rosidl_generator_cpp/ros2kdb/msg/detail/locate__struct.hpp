// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from ros2kdb:msg/Locate.idl
// generated code does not contain a copyright notice

#ifndef ROS2KDB__MSG__DETAIL__LOCATE__STRUCT_HPP_
#define ROS2KDB__MSG__DETAIL__LOCATE__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__ros2kdb__msg__Locate __attribute__((deprecated))
#else
# define DEPRECATED__ros2kdb__msg__Locate __declspec(deprecated)
#endif

namespace ros2kdb
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Locate_
{
  using Type = Locate_<ContainerAllocator>;

  explicit Locate_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->gx = 0.0;
      this->gy = 0.0;
      this->gz = 0.0;
      this->ax = 0.0;
      this->ay = 0.0;
      this->az = 0.0;
      this->dist = 0.0;
    }
  }

  explicit Locate_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->gx = 0.0;
      this->gy = 0.0;
      this->gz = 0.0;
      this->ax = 0.0;
      this->ay = 0.0;
      this->az = 0.0;
      this->dist = 0.0;
    }
  }

  // field types and members
  using _gx_type =
    double;
  _gx_type gx;
  using _gy_type =
    double;
  _gy_type gy;
  using _gz_type =
    double;
  _gz_type gz;
  using _ax_type =
    double;
  _ax_type ax;
  using _ay_type =
    double;
  _ay_type ay;
  using _az_type =
    double;
  _az_type az;
  using _dist_type =
    double;
  _dist_type dist;

  // setters for named parameter idiom
  Type & set__gx(
    const double & _arg)
  {
    this->gx = _arg;
    return *this;
  }
  Type & set__gy(
    const double & _arg)
  {
    this->gy = _arg;
    return *this;
  }
  Type & set__gz(
    const double & _arg)
  {
    this->gz = _arg;
    return *this;
  }
  Type & set__ax(
    const double & _arg)
  {
    this->ax = _arg;
    return *this;
  }
  Type & set__ay(
    const double & _arg)
  {
    this->ay = _arg;
    return *this;
  }
  Type & set__az(
    const double & _arg)
  {
    this->az = _arg;
    return *this;
  }
  Type & set__dist(
    const double & _arg)
  {
    this->dist = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    ros2kdb::msg::Locate_<ContainerAllocator> *;
  using ConstRawPtr =
    const ros2kdb::msg::Locate_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<ros2kdb::msg::Locate_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<ros2kdb::msg::Locate_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      ros2kdb::msg::Locate_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<ros2kdb::msg::Locate_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      ros2kdb::msg::Locate_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<ros2kdb::msg::Locate_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<ros2kdb::msg::Locate_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<ros2kdb::msg::Locate_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__ros2kdb__msg__Locate
    std::shared_ptr<ros2kdb::msg::Locate_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__ros2kdb__msg__Locate
    std::shared_ptr<ros2kdb::msg::Locate_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Locate_ & other) const
  {
    if (this->gx != other.gx) {
      return false;
    }
    if (this->gy != other.gy) {
      return false;
    }
    if (this->gz != other.gz) {
      return false;
    }
    if (this->ax != other.ax) {
      return false;
    }
    if (this->ay != other.ay) {
      return false;
    }
    if (this->az != other.az) {
      return false;
    }
    if (this->dist != other.dist) {
      return false;
    }
    return true;
  }
  bool operator!=(const Locate_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Locate_

// alias to use template instance with default allocator
using Locate =
  ros2kdb::msg::Locate_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace ros2kdb

#endif  // ROS2KDB__MSG__DETAIL__LOCATE__STRUCT_HPP_
