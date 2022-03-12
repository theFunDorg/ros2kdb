// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from ros2kdb:msg/ElevonInput.idl
// generated code does not contain a copyright notice

#ifndef ROS2KDB__MSG__DETAIL__ELEVON_INPUT__TRAITS_HPP_
#define ROS2KDB__MSG__DETAIL__ELEVON_INPUT__TRAITS_HPP_

#include "ros2kdb/msg/detail/elevon_input__struct.hpp"
#include <stdint.h>
#include <rosidl_runtime_cpp/traits.hpp>
#include <sstream>
#include <string>
#include <type_traits>

namespace rosidl_generator_traits
{

inline void to_yaml(
  const ros2kdb::msg::ElevonInput & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: l_spd
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "l_spd: ";
    value_to_yaml(msg.l_spd, out);
    out << "\n";
  }

  // member: r_spd
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "r_spd: ";
    value_to_yaml(msg.r_spd, out);
    out << "\n";
  }

  // member: l_pos
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "l_pos: ";
    value_to_yaml(msg.l_pos, out);
    out << "\n";
  }

  // member: r_pos
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "r_pos: ";
    value_to_yaml(msg.r_pos, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ros2kdb::msg::ElevonInput & msg)
{
  std::ostringstream out;
  to_yaml(msg, out);
  return out.str();
}

template<>
inline const char * data_type<ros2kdb::msg::ElevonInput>()
{
  return "ros2kdb::msg::ElevonInput";
}

template<>
inline const char * name<ros2kdb::msg::ElevonInput>()
{
  return "ros2kdb/msg/ElevonInput";
}

template<>
struct has_fixed_size<ros2kdb::msg::ElevonInput>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<ros2kdb::msg::ElevonInput>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<ros2kdb::msg::ElevonInput>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // ROS2KDB__MSG__DETAIL__ELEVON_INPUT__TRAITS_HPP_
