#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

#define KXVER 3
#include "k.h"
####
using std::placeholders::_1;

std::map<char,int> kAtomMap;
std::map<char,int> topicToMsgMap;
std::map<char,int> kConvMap;
std::map<char,int> topicToSubMap;

int hndl;
class MinimalSubscriber : public rclcpp::Node
{
  public:
    MinimalSubscriber()
    : Node("minimal_subscriber")
    {
    // Creating the Subscriptions
    for ( const auto &[key, value]: topicToMsgMap ) {
      topicToSubMap[key]=this->create_subscription<std_msgs::msg::String>(
      key, 10, std::bind(&MinimalSubscriber::topic_callback, this, _1));
    }
    }
####
  private:
    void topic_callback(const std_msgs::msg::String::SharedPtr msg) const
    {
      auto mStg=const_cast<char*>(msg->data.c_str());
      RCLCPP_INFO(this->get_logger(), "I heard: '%s'", msg->data.c_str());
      K msgRec=kp(mStg);
      k(hndl,".ros.receive",msgRec,(K)0);
    }
    // Attaching the subscriptions
    for ( const auto &[key, value]: topicToSubMap ) {
      rclcpp::Subscription<std_msgs::msg::String>::SharedPtr value;
    }


};
####
int main(int argc, char * argv[])
{

  hndl = khpu("localhost", 1234,"myusername:mypassword");
  K r = k(hndl,".ros.subInit[]",(K)0);

  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<MinimalSubscriber>());
  rclcpp::shutdown();
  return 0;
}
