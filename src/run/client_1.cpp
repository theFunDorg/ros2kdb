
#include <chrono>
#include <memory>
#include <vector>
#include <cstdlib>
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#define KXVER 3
#include "k.h"
// Adding custom message header files

#include "racer_interfaces/srv/serve.hpp"

#include "racer_interfaces/srv/edf_state.hpp"

#include "racer_interfaces/srv/level_positions.hpp"

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
class KDBClient_1 : public rclcpp::Node
{
public:
  KDBClient_1()
  : Node("KDBClient_1")
  {

    client_l_srv_srv=this->create_client<racer_interfaces::srv::Serve>("client_l_srv_srv");

    client_l_srv_es=this->create_client<racer_interfaces::srv::EdfState>("client_l_srv_es");

    client_r_srv_lp=this->create_client<racer_interfaces::srv::LevelPositions>("client_r_srv_lp");

    timer_ = this->create_wall_timer(0ms, std::bind(&KDBClient_1::timer_callback, this));
  }
private:

  void func_client_l_srv_srv(K data) 
  { 
    auto request = std::make_shared<racer_interfaces::srv::Serve::Request>();
      
      request->input_a = kJ(data)[0];
      request->input_b = kJ(data)[1];
    // Wait for the result.
    using ServiceResponseFuture =
      rclcpp::Client<racer_interfaces::srv::Serve>::SharedFuture;
    auto response_received_callback = [this](ServiceResponseFuture future) {
      
        K resp=knk(1, kf(((future.get())->output_c)));
        k(hndl,"{.ros.clientResponse[`KDB_Serve;x]}",resp,(K)0);
      };
    client_l_srv_srv->async_send_request(request,response_received_callback);
  }

  void func_client_l_srv_es(K data) 
  { 
    auto request = std::make_shared<racer_interfaces::srv::EdfState::Request>();
      
      request->action = kS(data)[0];
    // Wait for the result.
    using ServiceResponseFuture =
      rclcpp::Client<racer_interfaces::srv::EdfState>::SharedFuture;
    auto response_received_callback = [this](ServiceResponseFuture future) {
      
        K resp=knk(1, kh(((future.get())->successs)));
        k(hndl,"{.ros.clientResponse[`KDB_EdfState;x]}",resp,(K)0);
      };
    client_l_srv_es->async_send_request(request,response_received_callback);
  }

  void func_client_r_srv_lp(K data) 
  { 
    auto request = std::make_shared<racer_interfaces::srv::LevelPositions::Request>();
      
      request->exec = kH(data)[0];
    // Wait for the result.
    using ServiceResponseFuture =
      rclcpp::Client<racer_interfaces::srv::LevelPositions>::SharedFuture;
    auto response_received_callback = [this](ServiceResponseFuture future) {
      
        K resp=knk(1, kh(((future.get())->successs)));
        k(hndl,"{.ros.clientResponse[`KDB_LevelPositions;x]}",resp,(K)0);
      };
    client_r_srv_lp->async_send_request(request,response_received_callback);
  }

  void timer_callback()
  {
    response= k((-hndl), (S) 0); 
    topic=kK(response)[0];
    data=kK(response)[1]; 
    switch( checkString( topic->s , funcVect ) ) {

        case 0 :
           func_client_l_srv_srv(data);
           break; 

        case 1 :
           func_client_l_srv_es(data);
           break; 

        case 2 :
           func_client_r_srv_lp(data);
           break; 

       default :
           RCLCPP_INFO(this->get_logger(), "string out of range");
    }
  }
  rclcpp::TimerBase::SharedPtr timer_;

  rclcpp::Client<racer_interfaces::srv::Serve>::SharedPtr client_l_srv_srv;  

  rclcpp::Client<racer_interfaces::srv::EdfState>::SharedPtr client_l_srv_es;  

  rclcpp::Client<racer_interfaces::srv::LevelPositions>::SharedPtr client_r_srv_lp;  

};
int main(int argc, char * argv[])
{

  funcVect.push_back ("func_client_l_srv_srv");

  funcVect.push_back ("func_client_l_srv_es");

  funcVect.push_back ("func_client_r_srv_lp");

  hndl = khpu("0.0.0.0", 4567,"myusername:mypassword");
  K r = k(hndl,".ros.clientInit[]",(K)0);
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<KDBClient_1>());
  rclcpp::shutdown();
  return 0;
}
