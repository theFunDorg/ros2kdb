// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from ros2kdb:msg/Antenna.idl
// generated code does not contain a copyright notice

#ifndef ROS2KDB__MSG__DETAIL__ANTENNA__TRAITS_HPP_
#define ROS2KDB__MSG__DETAIL__ANTENNA__TRAITS_HPP_

#include "ros2kdb/msg/detail/antenna__struct.hpp"
#include <stdint.h>
#include <rosidl_runtime_cpp/traits.hpp>
#include <sstream>
#include <string>
#include <type_traits>

namespace rosidl_generator_traits
{

inline void to_yaml(
  const ros2kdb::msg::Antenna & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: data
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "data: ";
    value_to_yaml(msg.data, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ros2kdb::msg::Antenna & msg)
{
  std::ostringstream out;
  to_yaml(msg, out);
  return out.str();
}

template<>
inline const char * data_type<ros2kdb::msg::Antenna>()
{
  return "ros2kdb::msg::Antenna";
}

template<>
inline const char * name<ros2kdb::msg::Antenna>()
{
  return "ros2kdb/msg/Antenna";
}

template<>
struct has_fixed_size<ros2kdb::msg::Antenna>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<ros2kdb::msg::Antenna>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<ros2kdb::msg::Antenna>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // ROS2KDB__MSG__DETAIL__ANTENNA__TRAITS_HPP_
