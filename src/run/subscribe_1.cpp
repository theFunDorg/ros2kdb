
#include <memory>
#include "rclcpp/rclcpp.hpp"
//#include "std_msgs/msg/string.hpp"
#define KXVER 3
#include "k.h"

#include "racer_interfaces/msg/engine_actuate.hpp"

#include "racer_interfaces/msg/engine_sensor.hpp"

using std::placeholders::_1;
int hndl;
class KDBSubscriber_1 : public rclcpp::Node
{
  public:
    KDBSubscriber_1()
    : Node("KDBSubscriber_1")
    {
    // Creating the Subscriptions

      subscription_l_eng_actuate=this->create_subscription<racer_interfaces::msg::EngineActuate>(
      "/l_engine/actuator", 10, std::bind(&KDBSubscriber_1::callback_l_eng_actuate, this, _1));

      subscription_r_eng_sense=this->create_subscription<racer_interfaces::msg::EngineSensor>(
      "/r_engine/sensor", 10, std::bind(&KDBSubscriber_1::callback_r_eng_sense, this, _1));

    }
  private:

    void callback_l_eng_actuate(const racer_interfaces::msg::EngineActuate::SharedPtr msg) const
    {
      K msgRec=knk(5,ki( (msg->l_elevon)),ki( (msg->r_elevon)),ki( (msg->v_nozzle)),ki( (msg->h_nozzle)),( (msg->int32   edf)));
      k(hndl,"{[x] .ros.receive[\"/l_engine/actuator\";x]}",msgRec,(K)0);
    }

    void callback_r_eng_sense(const racer_interfaces::msg::EngineSensor::SharedPtr msg) const
    {
      K msgRec=knk(7,( (msg->int32   height)),( (msg->float32 ax)),( (msg->float32 ay)),( (msg->float32 az)),( (msg->float32 gx)),( (msg->float32 gy)),( (msg->float32 gz)));
      k(hndl,"{[x] .ros.receive[\"/r_engine/sensor\";x]}",msgRec,(K)0);
    }

    // Attaching the subscriptions

      rclcpp::Subscription<racer_interfaces::msg::EngineActuate>::SharedPtr subscription_l_eng_actuate;

      rclcpp::Subscription<racer_interfaces::msg::EngineSensor>::SharedPtr subscription_r_eng_sense;

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
