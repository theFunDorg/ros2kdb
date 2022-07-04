#include <chrono>
#include <memory>
#include <vector>
#include "rclcpp/rclcpp.hpp"
//#include "std_msgs/msg/string.hpp"
#define KXVER 3
#include "k.h"
// Adding custom message header files
#####FORLOOP
#include "MSG_PKG/msg/HEADER_NAME.hpp"
######LOOPEND

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

class NODE_NAME : public rclcpp::Node
{
public:
  NODE_NAME()
  : Node("NODE_NAME"), count_(0)
  {
#####FORLOOP
    publisher_PUBLISHER_NAME = this->create_publisher<MSG_PKG::msg::MSG_FILE>("TOPIC_NAME", 10);
######LOOPEND    
    timer_ = this->create_wall_timer(0ms, std::bind(&NODE_NAME::timer_callback, this));
  }

private:
#####FORLOOP
  void publish_PUBLISHER_NAME(K data) 
  { 
    auto msg = MSG_PKG::msg::MSG_FILE();
    KDB_PARAM_LIST
    publisher_PUBLISHER_NAME->publish(msg);
  }
#####LOOPEND

  void timer_callback()
  {
    response= k(hndl, (S) 0); 
    topic=kK(response)[0];
    data=kK(response)[1]; 
    switch( checkString( topic->s , funcVect ) ) {
#####FORLOOP
        case INDEX :
           publish_PUBLISHER_NAME(data);
           break; 
#####LOOPEND
       default :
           RCLCPP_INFO(this->get_logger(), "string out of range");
    }
  }

  rclcpp::TimerBase::SharedPtr timer_;

#####FORLOOP
  rclcpp::Publisher<MSG_PKG::msg::MSG_FILE>::SharedPtr publisher_PUBLISHER_NAME;
#####LOOPEND

  size_t count_;
};

int main(int argc, char * argv[])
{
#####FORLOOP
  funcVect.push_back ("publish_PUBLISHER_NAME");
#####LOOPEND

  hndl = khpu("KDB_HOST", PORT,"KDB_UNAME_PWD");
  K r = k(hndl,".ros.pubInit[]",(K)0);

  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<NODE_NAME>());
  rclcpp::shutdown();
  return 0;
}
