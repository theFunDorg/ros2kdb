#include <chrono>
#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

#define KXVER 3
#include "k.h"

int hndl;
using namespace std::chrono_literals;

std::map<char,int> kAtomMap;
std::map<char,int> msgMap;
std::map<char,int> kConvMap;
std::map<char,int> pubMap;

class MinimalPublisher : public rclcpp::Node
{
public:
  MinimalPublisher()
  : Node("minimal_publisher"), count_(0)
  {
    publisher_ = this->create_publisher<std_msgs::msg::String>("topic", 10);
    timer_ = this->create_wall_timer(
      500ms, std::bind(&MinimalPublisher::timer_callback, this));
  }

private:
  void timer_callback()
  {
    auto message = std_msgs::msg::String();
    //K response= k(hndl, (S) 0);
    //message.data = "Hello, world! " + std::to_string(response->i);
    message.data = "Hello, world! ";
    //r0(response);
    RCLCPP_INFO(this->get_logger(), "Publishing: '%s'", message.data.c_str());
    publisher_->publish(message);
    //k(hndl,"a+:1",(K)0);
  }
  rclcpp::TimerBase::SharedPtr timer_;
  rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
  size_t count_;
};

int main(int argc, char * argv[])
{
  hndl = khpu("localhost", 1234,"myusername:mypassword");
  K r = k(hndl,".ros.pubInit[]",(K)0);

  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<MinimalPublisher>());
  rclcpp::shutdown();
  return 0;
}
