
#include <chrono>
#include <memory>
#include <vector>
#include "rclcpp/rclcpp.hpp"
//#include "std_msgs/msg/string.hpp"
#define KXVER 3
#include "k.h"
// Adding custom message header files

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
class KDBPublisher_3 : public rclcpp::Node
{
public:
  KDBPublisher_3()
  : Node("KDBPublisher_3"), count_(0)
  {

    timer_ = this->create_wall_timer(0ms, std::bind(&KDBPublisher_3::timer_callback, this));
  }
private:

  void timer_callback()
  {
    response= k(hndl, (S) 0); 
    topic=kK(response)[0];
    data=kK(response)[1]; 
    switch( checkString( topic->s , funcVect ) ) {

       default :
           RCLCPP_INFO(this->get_logger(), "string out of range");
    }
  }
  rclcpp::TimerBase::SharedPtr timer_;

  size_t count_;
};
int main(int argc, char * argv[])
{

  hndl = khpu("0.0.0.0", 2345,"myusername:mypassword");
  K r = k(hndl,".ros.pubInit[]",(K)0);
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<KDBPublisher_3>());
  rclcpp::shutdown();
  return 0;
}
