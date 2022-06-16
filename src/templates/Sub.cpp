#include <memory>
#include "rclcpp/rclcpp.hpp"
//#include "std_msgs/msg/string.hpp"

#define KXVER 3
#include "k.h"
#####FORLOOP
#include "MSG_PKG/msg/HEADER_NAME.hpp"
######LOOPEND

using std::placeholders::_1;

int hndl;
class MinimalSubscriber : public rclcpp::Node
{
  public:
    MinimalSubscriber()
    : Node("minimal_subscriber")
    {
    // Creating the Subscriptions
#####FORLOOP
      subscription_SUBSCRIPTION_NAME=this->create_subscription<MSG_PKG::msg::MSG_FILE>(
      "TOPIC_NAME", 10, std::bind(&MinimalSubscriber::callback_SUBSCRIPTION_NAME, this, _1));
######LOOPEND
    }

  private:
#####FORLOOP
    void callback_SUBSCRIPTION_NAME(const MSG_PKG::msg::MSG_FILE::SharedPtr msg) const
    {
      K msgRec=knk(KDB_PARAM_LIST);
      k(hndl,"{[x] .ros.receive[\"TOPIC_NAME\";x]}",msgRec,(K)0);
    }
#####LOOPEND


    // Attaching the subscriptions
#####FORLOOP
      rclcpp::Subscription<MSG_PKG::msg::MSG_FILE>::SharedPtr subscription_SUBSCRIPTION_NAME;
#####LOOPEND
    };

int main(int argc, char * argv[])
{

  hndl = - khpu("localhost", PORT,"myusername:mypassword");
  K r = k(hndl,".ros.subInit[]",(K)0);

  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<MinimalSubscriber>());
  rclcpp::shutdown();
  return 0;
}