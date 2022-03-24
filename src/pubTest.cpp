
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
std::vector<std::string> funcVect;

int checkString (std::string inp, std::vector<std::string> vct)
{
  for(unsigned int i = 0; i < vct.size(); i++) {
      if(vct[i]==inp){
          return i;
      }
  }
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

    timer_ = this->create_wall_timer(2ms, std::bind(&MinimalPublisher::timer_callback, this));

  }

// ======================================================================
  void publish_r_act_ex() 
  { 
    auto msg = podracer_interfaces::msg::ExhaustInput();
    msg.tl_spd=kK(response)[0]->f;
    msg.tr_spd=kK(response)[1]->f;
    msg.bl_spd=kK(response)[2]->f;
    msg.br_spd=kK(response)[3]->f;
    msg.tl_pos=kK(response)[4]->f;
    msg.tr_pos=kK(response)[5]->f;
    msg.bl_pos=kK(response)[6]->f;
    msg.br_pos=kK(response)[7]->f;
    publisher_r_act_ex->publish(msg);
  }

  void publish_l_act_edf() 
  { 
    auto msg = podracer_interfaces::msg::EdfInput();
    msg.speed=kK(response)[0]->f;
    publisher_l_act_edf->publish(msg);
  }
// ======================================================================

private:
  void timer_callback()
  {
    response= k(hndl, (S) 0); 

    switch( checkString( kK(response)[0]->s , funcVect ) ) {
        case 0 :
           publish_r_act_ex();
           break; 
        case 1 :
           publish_l_act_edf();
           break;   
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

  hndl = khpu("localhost", 1234,"myusername:mypassword");
  k(hndl,".ros.pubInit[]",(K)0);
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<MinimalPublisher>());
  rclcpp::shutdown();
  return 0;
}