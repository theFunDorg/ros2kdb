// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from ros2kdb:msg/ExhaustOutput.idl
// generated code does not contain a copyright notice

#ifndef ROS2KDB__MSG__DETAIL__EXHAUST_OUTPUT__TRAITS_HPP_
#define ROS2KDB__MSG__DETAIL__EXHAUST_OUTPUT__TRAITS_HPP_

#include "ros2kdb/msg/detail/exhaust_output__struct.hpp"
#include <stdint.h>
#include <rosidl_runtime_cpp/traits.hpp>
#include <sstream>
#include <string>
#include <type_traits>

namespace rosidl_generator_traits
{

inline void to_yaml(
  const ros2kdb::msg::ExhaustOutput & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: tl_pos
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "tl_pos: ";
    value_to_yaml(msg.tl_pos, out);
    out << "\n";
  }

  // member: tr_pos
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "tr_pos: ";
    value_to_yaml(msg.tr_pos, out);
    out << "\n";
  }

  // member: bl_pos
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "bl_pos: ";
    value_to_yaml(msg.bl_pos, out);
    out << "\n";
  }

  // member: br_pos
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "br_pos: ";
    value_to_yaml(msg.br_pos, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ros2kdb::msg::ExhaustOutput & msg)
{
  std::ostringstream out;
  to_yaml(msg, out);
  return out.str();
}

template<>
inline const char * data_type<ros2kdb::msg::ExhaustOutput>()
{
  return "ros2kdb::msg::ExhaustOutput";
}

template<>
inline const char * name<ros2kdb::msg::ExhaustOutput>()
{
  return "ros2kdb/msg/ExhaustOutput";
}

template<>
struct has_fixed_size<ros2kdb::msg::ExhaustOutput>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<ros2kdb::msg::ExhaustOutput>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<ros2kdb::msg::ExhaustOutput>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // ROS2KDB__MSG__DETAIL__EXHAUST_OUTPUT__TRAITS_HPP_
