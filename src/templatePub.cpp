#include <chrono>
#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

#define KXVER 3
#include "k.h"
// Adding custom message header files
#####FORLOOP
#include "podracer_interfaces/msg/HEADER_NAME.hpp"
######LOOPEND

int hndl;
using namespace std::chrono_literals;

class MinimalPublisher : public rclcpp::Node
{
public:
  MinimalPublisher()
  : Node("minimal_publisher"), count_(0)
  {
    std::map<string, string> funcDict;
#####FORLOOP
    publisher_PUBLISHER_NAME = this->create_publisher<podracer_interfaces::msg::MSG_FILE>("TOPIC_NAME", 10);
######LOOPEND    

    timer_ = this->create_wall_timer(0ms, std::bind(&MinimalPublisher::timer_callback, this));
  }

private:
#####FORLOOP
  void publish_PUBLISHER_NAME(K response) 
  { 
    auto msg = podracer_interfaces::msg::MSG_FILE();
    KDB_PARAM_LIST;
    publisher_PUBLISHER_NAME->publish(msg);
  }
#####LOOPEND

#####FORLOOP
  funcDict.insert(pair<string, string>("PUBLISHER_NAME", publisher_PUBLISHER_NAME));
#####LOOPEND

  void timer_callback()
  {
    response= k(hndl, (S) 0); 

    publisher_PUBLISHER_NAME->publish(message);
  }

  rclcpp::TimerBase::SharedPtr timer_;

#####FORLOOP
  rclcpp::Publisher<podracer_interfaces::msg::MSG_FILE>::SharedPtr publisher_PUBLISHER_NAME;
#####LOOPEND

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
