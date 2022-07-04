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
class NODE_NAME : public rclcpp::Node
{
  public:
    NODE_NAME()
    : Node("NODE_NAME")
    {
    // Creating the Subscriptions
#####FORLOOP
      subscription_SUBSCRIPTION_NAME=this->create_subscription<MSG_PKG::msg::MSG_FILE>(
      "TOPIC_NAME", 10, std::bind(&NODE_NAME::callback_SUBSCRIPTION_NAME, this, _1));
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

  hndl = khpu("KDB_HOST", PORT,"KDB_UNAME_PWD");
  K r = k(hndl,".ros.subInit[]",(K)0);

  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<NODE_NAME>());
  rclcpp::shutdown();
  return 0;
}
