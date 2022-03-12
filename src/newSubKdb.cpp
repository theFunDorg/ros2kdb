
#include <memory>
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#define KXVER 3
#include "k.h"

#include "msg/ExhaustInput.hpp"

#include "msg/ExhaustInput.hpp"

#include "msg/EdfInput.hpp"

#include "msg/ElevonInput.hpp"

#include "msg/EdfInput.hpp"

#include "msg/ElevonInput.hpp"

#include "msg/ElevonInput.hpp"

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
      "r_pod/actuate/exhaust", 10, std::bind(&MinimalSubscriber::callback_r_act_ex, this, _1));

      subscription_l_act_ex=this->create_subscription<ExhaustInput>(
      "l_pod/actuate/exhaust", 10, std::bind(&MinimalSubscriber::callback_l_act_ex, this, _1));

      subscription_r_act_edf=this->create_subscription<EdfInput>(
      "r_pod/actuate/edf", 10, std::bind(&MinimalSubscriber::callback_r_act_edf, this, _1));

      subscription_r_act_elev=this->create_subscription<ElevonInput>(
      "r_pod/actuate/elevon", 10, std::bind(&MinimalSubscriber::callback_r_act_elev, this, _1));

      subscription_l_act_edf=this->create_subscription<EdfInput>(
      "l_pod/actuate/edf", 10, std::bind(&MinimalSubscriber::callback_l_act_edf, this, _1));

      subscription_c_act_elev=this->create_subscription<ElevonInput>(
      "c_pod/actuate/elevon", 10, std::bind(&MinimalSubscriber::callback_c_act_elev, this, _1));

      subscription_l_act_elev=this->create_subscription<ElevonInput>(
      "l_pod/actuate/elevon", 10, std::bind(&MinimalSubscriber::callback_l_act_elev, this, _1));

    }
    }

  private:
    void callback_r_act_ex(const ExhaustInput::SharedPtr msg) const
    {
      auto mStg=const_cast<char*>(msg->data.c_str());
      RCLCPP_INFO(this->get_logger(), "I heard: '%s'", msg->data.c_str());
      K msgRec=knk(8,kF(tl_spd),kF(tr_spd),kF(bl_spd),kF(br_spd),kF(tl_pos),kF(tr_pos),kF(bl_pos),kF(br_pos));
      k(hndl,"{[x] .ros.receive[r_pod/actuate/exhaust;x]}",msgRec,(K)0);
    }

  private:
    void callback_l_act_ex(const ExhaustInput::SharedPtr msg) const
    {
      auto mStg=const_cast<char*>(msg->data.c_str());
      RCLCPP_INFO(this->get_logger(), "I heard: '%s'", msg->data.c_str());
      K msgRec=knk(8,kF(tl_spd),kF(tr_spd),kF(bl_spd),kF(br_spd),kF(tl_pos),kF(tr_pos),kF(bl_pos),kF(br_pos));
      k(hndl,"{[x] .ros.receive[l_pod/actuate/exhaust;x]}",msgRec,(K)0);
    }

  private:
    void callback_r_act_edf(const EdfInput::SharedPtr msg) const
    {
      auto mStg=const_cast<char*>(msg->data.c_str());
      RCLCPP_INFO(this->get_logger(), "I heard: '%s'", msg->data.c_str());
      K msgRec=knk(1,kF(speed));
      k(hndl,"{[x] .ros.receive[r_pod/actuate/edf;x]}",msgRec,(K)0);
    }

  private:
    void callback_r_act_elev(const ElevonInput::SharedPtr msg) const
    {
      auto mStg=const_cast<char*>(msg->data.c_str());
      RCLCPP_INFO(this->get_logger(), "I heard: '%s'", msg->data.c_str());
      K msgRec=knk(4,kF(l_spd),kF(r_spd),kF(l_pos),kF(r_pos));
      k(hndl,"{[x] .ros.receive[r_pod/actuate/elevon;x]}",msgRec,(K)0);
    }

  private:
    void callback_l_act_edf(const EdfInput::SharedPtr msg) const
    {
      auto mStg=const_cast<char*>(msg->data.c_str());
      RCLCPP_INFO(this->get_logger(), "I heard: '%s'", msg->data.c_str());
      K msgRec=knk(1,kF(speed));
      k(hndl,"{[x] .ros.receive[l_pod/actuate/edf;x]}",msgRec,(K)0);
    }

  private:
    void callback_c_act_elev(const ElevonInput::SharedPtr msg) const
    {
      auto mStg=const_cast<char*>(msg->data.c_str());
      RCLCPP_INFO(this->get_logger(), "I heard: '%s'", msg->data.c_str());
      K msgRec=knk(4,kF(l_spd),kF(r_spd),kF(l_pos),kF(r_pos));
      k(hndl,"{[x] .ros.receive[c_pod/actuate/elevon;x]}",msgRec,(K)0);
    }

  private:
    void callback_l_act_elev(const ElevonInput::SharedPtr msg) const
    {
      auto mStg=const_cast<char*>(msg->data.c_str());
      RCLCPP_INFO(this->get_logger(), "I heard: '%s'", msg->data.c_str());
      K msgRec=knk(4,kF(l_spd),kF(r_spd),kF(l_pos),kF(r_pos));
      k(hndl,"{[x] .ros.receive[l_pod/actuate/elevon;x]}",msgRec,(K)0);
    }

    // Attaching the subscriptions

      rclcpp::subscription_r_act_ex<ExhaustInput>::SharedPtr value;

      rclcpp::subscription_l_act_ex<ExhaustInput>::SharedPtr value;

      rclcpp::subscription_r_act_edf<EdfInput>::SharedPtr value;

      rclcpp::subscription_r_act_elev<ElevonInput>::SharedPtr value;

      rclcpp::subscription_l_act_edf<EdfInput>::SharedPtr value;

      rclcpp::subscription_c_act_elev<ElevonInput>::SharedPtr value;

      rclcpp::subscription_l_act_elev<ElevonInput>::SharedPtr value;

    }
};
int main(int argc, char * argv[])
{
  hndl = khpu("localhost", 1234,"myusername:mypassword");
  K r = k(hndl,".ros.subInit[]",(K)0);
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<MinimalSubscriber>());
  rclcpp::shutdown();
  return 0;
}
