
#include <memory>
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#define KXVER 3
#include "k.h"

#include "podracer_interfaces/msg/elevon_input.hpp"
#include "podracer_interfaces/msg/elevon_input.hpp"
#include "podracer_interfaces/msg/elevon_input.hpp"
#include "podracer_interfaces/msg/elevon_input.hpp"
#include "podracer_interfaces/msg/elevon_input.hpp"
#include "podracer_interfaces/msg/elevon_input.hpp"
#include "podracer_interfaces/msg/elevon_input.hpp"

using std::placeholders::_1;
int hndl;
class MinimalSubscriber : public rclcpp::Node
{
  public:
    MinimalSubscriber()
    : Node("minimal_subscriber")
    {
    // Creating the Subscriptions

      subscription_r_act_ex=this->create_subscription<ExhaustInput>(
      "/r_pod/actuate/exhaust", 10, std::bind(&MinimalSubscriber::callback_r_act_ex, this, _1));

      subscription_l_act_ex=this->create_subscription<ExhaustInput>(
      "/l_pod/actuate/exhaust", 10, std::bind(&MinimalSubscriber::callback_l_act_ex, this, _1));

      subscription_r_act_edf=this->create_subscription<EdfInput>(
      "/r_pod/actuate/edf", 10, std::bind(&MinimalSubscriber::callback_r_act_edf, this, _1));

      subscription_r_act_elev=this->create_subscription<ElevonInput>(
      "/r_pod/actuate/elevon", 10, std::bind(&MinimalSubscriber::callback_r_act_elev, this, _1));

      subscription_l_act_edf=this->create_subscription<EdfInput>(
      "/l_pod/actuate/edf", 10, std::bind(&MinimalSubscriber::callback_l_act_edf, this, _1));

      subscription_c_act_elev=this->create_subscription<ElevonInput>(
      "/c_pod/actuate/elevon", 10, std::bind(&MinimalSubscriber::callback_c_act_elev, this, _1));

      subscription_l_act_elev=this->create_subscription<ElevonInput>(
      "/l_pod/actuate/elevon", 10, std::bind(&MinimalSubscriber::callback_l_act_elev, this, _1));

    }
  private:

    void callback_r_act_ex(const ExhaustInput::SharedPtr msg) const
    {
      K msgRec=knk(8,kF(float64 (msg->tl_spd)),kF(float64 (msg->tr_spd)),kF(float64 (msg->bl_spd)),kF(float64 (msg->br_spd)),kF(float64 (msg->tl_pos)),kF(float64 (msg->tr_pos)),kF(float64 (msg->bl_pos)),kF(float64 (msg->br_pos)));
      k(hndl,"{[x] .ros.receive[\"/r_pod/actuate/exhaust\";x]}",msgRec,(K)0);
    }

    void callback_l_act_ex(const ExhaustInput::SharedPtr msg) const
    {
      K msgRec=knk(8,kF(float64 (msg->tl_spd)),kF(float64 (msg->tr_spd)),kF(float64 (msg->bl_spd)),kF(float64 (msg->br_spd)),kF(float64 (msg->tl_pos)),kF(float64 (msg->tr_pos)),kF(float64 (msg->bl_pos)),kF(float64 (msg->br_pos)));
      k(hndl,"{[x] .ros.receive[\"/l_pod/actuate/exhaust\";x]}",msgRec,(K)0);
    }

    void callback_r_act_edf(const EdfInput::SharedPtr msg) const
    {
      K msgRec=knk(1,kF(float64 (msg->speed)));
      k(hndl,"{[x] .ros.receive[\"/r_pod/actuate/edf\";x]}",msgRec,(K)0);
    }

    void callback_r_act_elev(const ElevonInput::SharedPtr msg) const
    {
      K msgRec=knk(4,kF(float64 (msg->l_spd)),kF(float64 (msg->r_spd)),kF(float64 (msg->l_pos)),kF(float64 (msg->r_pos)));
      k(hndl,"{[x] .ros.receive[\"/r_pod/actuate/elevon\";x]}",msgRec,(K)0);
    }

    void callback_l_act_edf(const EdfInput::SharedPtr msg) const
    {
      K msgRec=knk(1,kF(float64 (msg->speed)));
      k(hndl,"{[x] .ros.receive[\"/l_pod/actuate/edf\";x]}",msgRec,(K)0);
    }

    void callback_c_act_elev(const ElevonInput::SharedPtr msg) const
    {
      K msgRec=knk(4,kF(float64 (msg->l_spd)),kF(float64 (msg->r_spd)),kF(float64 (msg->l_pos)),kF(float64 (msg->r_pos)));
      k(hndl,"{[x] .ros.receive[\"/c_pod/actuate/elevon\";x]}",msgRec,(K)0);
    }

    void callback_l_act_elev(const ElevonInput::SharedPtr msg) const
    {
      K msgRec=knk(4,kF(float64 (msg->l_spd)),kF(float64 (msg->r_spd)),kF(float64 (msg->l_pos)),kF(float64 (msg->r_pos)));
      k(hndl,"{[x] .ros.receive[\"/l_pod/actuate/elevon\";x]}",msgRec,(K)0);
    }

    // Attaching the subscriptions

      rclcpp::Subscription<podracer_interfaces::msg::ExhaustInput>::SharedPtr subscription_r_act_ex;
      rclcpp::Subscription<podracer_interfaces::msg::ExhaustInput>::SharedPtr subscription_l_act_ex;
      rclcpp::Subscription<podracer_interfaces::msg::EdfInput>::SharedPtr subscription_r_act_edf;
      rclcpp::Subscription<podracer_interfaces::msg::ElevonInput>::SharedPtr subscription_r_act_elev;
      rclcpp::Subscription<podracer_interfaces::msg::EdfInput>::SharedPtr subscription_l_act_edf;
      rclcpp::Subscription<podracer_interfaces::msg::ElevonInput>::SharedPtr subscription_c_act_elev;
      rclcpp::Subscription<podracer_interfaces::msg::ElevonInput>::SharedPtr subscription_l_act_elev;

    };
int main(int argc, char * argv[])
{
  hndl = - khpu("localhost", 1234,"myusername:mypassword");
  K r = k(hndl,".ros.subInit[]",(K)0);
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<MinimalSubscriber>());
  rclcpp::shutdown();
  return 0;
}
