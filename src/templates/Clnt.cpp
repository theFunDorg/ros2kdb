#include <chrono>
#include <memory>
#include <vector>
#include <cstdlib>
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#define KXVER 3
#include "k.h"

// Adding custom message header files
#####FORLOOP
#include "podracer_interfaces/srv/serve.hpp"
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
  return 999;
};

using namespace std::chrono_literals;


class MinimalClient : public rclcpp::Node
{
public:
  MinimalClient()
  : Node("minimal_client")
  {
#####FORLOOP
    client_serve_kdb=this->create_client<podracer_interfaces::srv::Serve>("kdbFunc");
######LOOPEND
    timer_ = this->create_wall_timer(0ms, std::bind(&MinimalClient::timer_callback, this));
  }

private:
#####FORLOOP
  void func_client_serve_kdb(K data) 
  { 
    auto request = std::make_shared<podracer_interfaces::srv::Serve::Request>();
      request->avalu = kI(data)[0];
      request->bvalu = kI(data)[1];
    // Wait for the result.
    using ServiceResponseFuture =
      rclcpp::Client<podracer_interfaces::srv::Serve>::SharedFuture;
    auto response_received_callback = [this](ServiceResponseFuture future) {
        K resp=kf((future.get())->cvalu);
        k(hndl,"{.ros.clientResponse[`funcServKDB;x]}",resp,(K)0);
      };
    client_serve_kdb->async_send_request(request,response_received_callback);
  }
######LOOPEND

  void timer_callback()
  {
    response= k((-hndl), (S) 0); 
    topic=kK(response)[0];
    data=kK(response)[1]; 
    switch( checkString( topic->s , funcVect ) ) {
#####FORLOOP
        case INDEX :
           func_client_serve_kdb(data);
           break; 
######LOOPEND
       default :
           RCLCPP_INFO(this->get_logger(), "string out of range");
    }
  }
  rclcpp::TimerBase::SharedPtr timer_;
#####FORLOOP
  rclcpp::Client<podracer_interfaces::srv::Serve>::SharedPtr client_serve_kdb;  
######LOOPEND

};
int main(int argc, char * argv[])
{
#####FORLOOP
  funcVect.push_back ("func_client_serve_kdb");
######LOOPEND

  hndl = - khpu("0.0.0.0", 4567,"myusername:mypassword");
  K r = k(hndl,".ros.clientInit[]",(K)0);

  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<MinimalClient>());
  rclcpp::shutdown();
  return 0;
}
