
#include <chrono>
#include <memory>
#include <vector>
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#define KXVER 3
#include "k.h"
// Adding custom message header files

#include "podracer_interfaces/msg/exhaust_input.hpp"
#include "podracer_interfaces/msg/edf_input.hpp"

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

class MinimalPublisher : public rclcpp::Node
{
public:
  MinimalPublisher()
  : Node("minimal_publisher"), count_(0)
  {

    publisher_r_act_ex = this->create_publisher<podracer_interfaces::msg::ExhaustInput>("/r_pod/actuate/exhaust", 10);
    publisher_l_act_edf = this->create_publisher<podracer_interfaces::msg::EdfInput>("/l_pod/actuate/edf", 10);

    timer_ = this->create_wall_timer(20ms, std::bind(&MinimalPublisher::timer_callback, this));

  }

// ======================================================================
  void publish_r_act_ex(K data) 
  { 
    RCLCPP_INFO(this->get_logger(), "Running publish_r_act_ex");
    auto msg = podracer_interfaces::msg::ExhaustInput();
    msg.tl_spd=kF(data)[0];
    msg.tr_spd=kF(data)[1];
    msg.bl_spd=kF(data)[2];
    msg.br_spd=kF(data)[3];
    msg.tl_pos=kF(data)[4];
    msg.tr_pos=kF(data)[5];
    msg.bl_pos=kF(data)[6];
    msg.br_pos=kF(data)[7];
    publisher_r_act_ex->publish(msg);
  }

  void publish_l_act_edf(K data) 
  { 
    RCLCPP_INFO(this->get_logger(), "Running publish_l_act_edf");
    auto msg = podracer_interfaces::msg::EdfInput();
    msg.speed=kF(data)[0];
    publisher_l_act_edf->publish(msg);
    RCLCPP_INFO(this->get_logger(), "Sent off to topic!");
  }
// ======================================================================

private:
  void timer_callback()
  {
    response= k(hndl, (S) 0); 
    topic=kK(response)[0];
    data=kK(response)[1]; 
    switch( checkString( topic->s , funcVect ) ) {
        case 0 :
           publish_r_act_ex(data);
           break; 
        case 1 :
           publish_l_act_edf(data);
           break;
       default :
           RCLCPP_INFO(this->get_logger(), "string out of range");
    }
  }

  rclcpp::TimerBase::SharedPtr timer_;

  rclcpp::Publisher<podracer_interfaces::msg::ExhaustInput>::SharedPtr publisher_r_act_ex;
  rclcpp::Publisher<podracer_interfaces::msg::EdfInput>::SharedPtr publisher_l_act_edf;

  size_t count_;
};
int main(int argc, char * argv[])
{
  funcVect.push_back ("publish_r_act_ex");
  funcVect.push_back ("publish_l_act_edf");

  hndl = khpu("0.0.0.0", 1234,"myusername:mypassword");
  k(hndl,".ros.pubInit[]",(K)0);
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<MinimalPublisher>());
  rclcpp::shutdown();
  return 0;
}