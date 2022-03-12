// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from ros2kdb:msg/Locate.idl
// generated code does not contain a copyright notice

#ifndef ROS2KDB__MSG__DETAIL__LOCATE__TRAITS_HPP_
#define ROS2KDB__MSG__DETAIL__LOCATE__TRAITS_HPP_

#include "ros2kdb/msg/detail/locate__struct.hpp"
#include <stdint.h>
#include <rosidl_runtime_cpp/traits.hpp>
#include <sstream>
#include <string>
#include <type_traits>

namespace rosidl_generator_traits
{

inline void to_yaml(
  const ros2kdb::msg::Locate & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: gx
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "gx: ";
    value_to_yaml(msg.gx, out);
    out << "\n";
  }

  // member: gy
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "gy: ";
    value_to_yaml(msg.gy, out);
    out << "\n";
  }

  // member: gz
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "gz: ";
    value_to_yaml(msg.gz, out);
    out << "\n";
  }

  // member: ax
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "ax: ";
    value_to_yaml(msg.ax, out);
    out << "\n";
  }

  // member: ay
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "ay: ";
    value_to_yaml(msg.ay, out);
    out << "\n";
  }

  // member: az
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "az: ";
    value_to_yaml(msg.az, out);
    out << "\n";
  }

  // member: dist
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "dist: ";
    value_to_yaml(msg.dist, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ros2kdb::msg::Locate & msg)
{
  std::ostringstream out;
  to_yaml(msg, out);
  return out.str();
}

template<>
inline const char * data_type<ros2kdb::msg::Locate>()
{
  return "ros2kdb::msg::Locate";
}

template<>
inline const char * name<ros2kdb::msg::Locate>()
{
  return "ros2kdb/msg/Locate";
}

template<>
struct has_fixed_size<ros2kdb::msg::Locate>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<ros2kdb::msg::Locate>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<ros2kdb::msg::Locate>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // ROS2KDB__MSG__DETAIL__LOCATE__TRAITS_HPP_
