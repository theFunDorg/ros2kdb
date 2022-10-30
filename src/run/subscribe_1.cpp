
#include <memory>
#include "rclcpp/rclcpp.hpp"
//#include "std_msgs/msg/string.hpp"
#define KXVER 3
#include "k.h"

#include "racer_interfaces/msg/engine_sensor.hpp"

#include "racer_interfaces/msg/engine_actuate.hpp"

using std::placeholders::_1;
int hndl;
class KDBSubscriber_1 : public rclcpp::Node
{
  public:
    KDBSubscriber_1()
    : Node("KDBSubscriber_1")
    {
    // Creating the Subscriptions

      subscription_l_eng_sense=this->create_subscription<racer_interfaces::msg::EngineSensor>(
      "/left_engine/engine_sensors", 10, std::bind(&KDBSubscriber_1::callback_l_eng_sense, this, _1));

      subscription_l_eng_actuate=this->create_subscription<racer_interfaces::msg::EngineActuate>(
      "/left_engine/controls", 10, std::bind(&KDBSubscriber_1::callback_l_eng_actuate, this, _1));

    }
  private:

    void callback_l_eng_sense(const racer_interfaces::msg::EngineSensor::SharedPtr msg) const
    {
      K msgRec=knk(7,ki( (msg->height)),kf( (msg->ax)),kf( (msg->ay)),kf( (msg->az)),kf( (msg->gx)),kf( (msg->gy)),kf( (msg->gz)));
      k(hndl,"{[x] .ros.receive[\"l_eng_sense\";x]}",msgRec,(K)0);
    }

    void callback_l_eng_actuate(const racer_interfaces::msg::EngineActuate::SharedPtr msg) const
    {
      K msgRec=knk(5,ki( (msg->l_elevon)),ki( (msg->r_elevon)),ki( (msg->v_nozzle)),ki( (msg->h_nozzle)),ki( (msg->edf)));
      k(hndl,"{[x] .ros.receive[\"l_eng_actuate\";x]}",msgRec,(K)0);
    }

    // Attaching the subscriptions

      rclcpp::Subscription<racer_interfaces::msg::EngineSensor>::SharedPtr subscription_l_eng_sense;

      rclcpp::Subscription<racer_interfaces::msg::EngineActuate>::SharedPtr subscription_l_eng_actuate;

    };
int main(int argc, char * argv[])
{
  hndl = khpu("0.0.0.0", 1234,"myusername:mypassword");
  K r = k(hndl,".ros.subInit[]",(K)0);
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<KDBSubscriber_1>());
  rclcpp::shutdown();
  return 0;
}
