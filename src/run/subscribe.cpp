
#include <memory>
#include "rclcpp/rclcpp.hpp"
//#include "std_msgs/msg/string.hpp"
#define KXVER 3
#include "k.h"

#include "podracer_interfaces/msg/exhaust_input.hpp"

#include "podracer_interfaces/msg/edf_input.hpp"

using std::placeholders::_1;
int hndl;
class MinimalSubscriber : public rclcpp::Node
{
  public:
    MinimalSubscriber()
    : Node("minimal_subscriber")
    {
    // Creating the Subscriptions

      subscription_r_act_ex=this->create_subscription<podracer_interfaces::msg::ExhaustInput>(
      "/r_pod/actuate/exhaust", 10, std::bind(&MinimalSubscriber::callback_r_act_ex, this, _1));

      subscription_l_act_edf=this->create_subscription<podracer_interfaces::msg::EdfInput>(
      "/l_pod/actuate/edf", 10, std::bind(&MinimalSubscriber::callback_l_act_edf, this, _1));

    }
  private:

    void callback_r_act_ex(const podracer_interfaces::msg::ExhaustInput::SharedPtr msg) const
    {
      K msgRec=knk(8,kf( (msg->tl_spd)),kf( (msg->tr_spd)),kf( (msg->bl_spd)),kf( (msg->br_spd)),kf( (msg->tl_pos)),kf( (msg->tr_pos)),kf( (msg->bl_pos)),kf( (msg->br_pos)));
      k(hndl,"{[x] .ros.receive[\"/r_pod/actuate/exhaust\";x]}",msgRec,(K)0);
    }

    void callback_l_act_edf(const podracer_interfaces::msg::EdfInput::SharedPtr msg) const
    {
      K msgRec=knk(1,kf( (msg->speed)));
      k(hndl,"{[x] .ros.receive[\"/l_pod/actuate/edf\";x]}",msgRec,(K)0);
    }

    // Attaching the subscriptions

      rclcpp::Subscription<podracer_interfaces::msg::ExhaustInput>::SharedPtr subscription_r_act_ex;

      rclcpp::Subscription<podracer_interfaces::msg::EdfInput>::SharedPtr subscription_l_act_edf;

    };
int main(int argc, char * argv[])
{
  hndl = - khpu("localhost", 2345,"myusername:mypassword");
  K r = k(hndl,".ros.subInit[]",(K)0);
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<MinimalSubscriber>());
  rclcpp::shutdown();
  return 0;
}
