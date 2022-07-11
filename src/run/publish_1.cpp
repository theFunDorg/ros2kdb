
#include <chrono>
#include <memory>
#include <vector>
#include "rclcpp/rclcpp.hpp"
//#include "std_msgs/msg/string.hpp"
#define KXVER 3
#include "k.h"
// Adding custom message header files

#include "racer_interfaces/msg/engine_actuate.hpp"
#include "racer_interfaces/msg/engine_sensor.hpp"

int hndl;
K response;
K data;
K topic;
std::vector<std::string> funcVect;
int checkString (std::string inp, std::vector<std::string> vct)

{
  for(unsigned int i = 0; i < vct.size(); i++) {
      if(vct[i]==inp){
          return (int) i;
      }
  }
  return 4;
};
using namespace std::chrono_literals;
class KDBPublisher_1 : public rclcpp::Node
{
public:
  KDBPublisher_1()
  : Node("KDBPublisher_1"), count_(0)
  {

    publisher_l_eng_actuate = this->create_publisher<racer_interfaces::msg::EngineActuate>("/l_engine/actuator", 10);
    publisher_r_eng_sense = this->create_publisher<racer_interfaces::msg::EngineSensor>("/r_engine/sensor", 10);
    timer_ = this->create_wall_timer(0ms, std::bind(&KDBPublisher_1::timer_callback, this));
  }
private:

  void publish_l_eng_actuate(K data) 
  { 
    auto msg = racer_interfaces::msg::EngineActuate();
    
    msg.l_elevon=kI(data)[0];
    msg.r_elevon=kI(data)[1];
    msg.v_nozzle=kI(data)[2];
    msg.h_nozzle=kI(data)[3];
    msg.edf=kI(data)[4];
    publisher_l_eng_actuate->publish(msg);
  }

  void publish_r_eng_sense(K data) 
  { 
    auto msg = racer_interfaces::msg::EngineSensor();
    
    msg.height=kI(data)[0];
    msg.ax=kF(data)[1];
    msg.ay=kF(data)[2];
    msg.az=kF(data)[3];
    msg.gx=kF(data)[4];
    msg.gy=kF(data)[5];
    msg.gz=kF(data)[6];
    publisher_r_eng_sense->publish(msg);
  }

  void timer_callback()
  {
    response= k(hndl, (S) 0); 
    topic=kK(response)[0];
    data=kK(response)[1]; 
    switch( checkString( topic->s , funcVect ) ) {
        case 0 :
           publish_l_eng_actuate(data);
           break; 
        case 1 :
           publish_r_eng_sense(data);
           break; 
       default :
           RCLCPP_INFO(this->get_logger(), "string out of range");
    }
  }
  rclcpp::TimerBase::SharedPtr timer_;

  rclcpp::Publisher<racer_interfaces::msg::EngineActuate>::SharedPtr publisher_l_eng_actuate;

  rclcpp::Publisher<racer_interfaces::msg::EngineSensor>::SharedPtr publisher_r_eng_sense;

  size_t count_;
};
int main(int argc, char * argv[])
{

  funcVect.push_back ("publish_l_eng_actuate");
  funcVect.push_back ("publish_r_eng_sense");
  hndl = khpu("0.0.0.0", 2345,"myusername:mypassword");
  K r = k(hndl,".ros.pubInit[]",(K)0);
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<KDBPublisher_1>());
  rclcpp::shutdown();
  return 0;
}
