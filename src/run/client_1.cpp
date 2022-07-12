
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

  void func_client_l_srv_srv(K data, auto client, auto node) 
  { 
    auto request = std::make_shared<racer_interfaces::srv::Serve::Request>();
      
      request->input_a = kJ(data)[0];
      request->input_b = kJ(data)[1];
    auto result = client->async_send_request(request);
    rclcpp::spin_until_future_complete(node, result);
    // Wait for the result.
    K resp=knk(1, kf(((future.get())->output_c)));
    k(hndl,"{.ros.clientResponse[`KDB_Serve;x]}",resp,(K)0);
  }

  void func_client_r_srv_lp(K data, auto client, auto node) 
  { 
    auto request = std::make_shared<racer_interfaces::srv::LevelPositions::Request>();
      
      request->exec = kH(data)[0];
    auto result = client->async_send_request(request);
    rclcpp::spin_until_future_complete(node, result);
    // Wait for the result.
    K resp=knk(1, kh(((future.get())->successs)));
    k(hndl,"{.ros.clientResponse[`KDB_LevelPositions;x]}",resp,(K)0);
  }

int main(int argc, char **argv)
  {
  // Add match strings for service names  

  funcVect.push_back ("l_srv_srv");

  funcVect.push_back ("r_srv_lp");

  hndl = khpu("0.0.0.0", 4567,"myusername:mypassword");
  K r = k(hndl,".ros.clientInit[]",(K)0);
  rclcpp::init(argc, argv);
  std::shared_ptr<rclcpp::Node> KDBClient_1 = rclcpp::Node::make_shared("KDBClient_1");

  rclcpp::Client<racer_interfaces::srv::Serve>::SharedPtr client_l_srv_srv;  
    client_l_srv_srv=this->create_client<racer_interfaces::srv::Serve>("l_srv_srv");

  rclcpp::Client<racer_interfaces::srv::LevelPositions>::SharedPtr client_r_srv_lp;  
    client_r_srv_lp=this->create_client<racer_interfaces::srv::LevelPositions>("r_srv_lp");

  // Loop to take in KDB+ data
  while (true) {
    response= k((-hndl), (S) 0); 
    topic=kK(response)[0];
    data=kK(response)[1]; 
    switch( checkString( topic->s , funcVect ) ) {

        case 0 :
           func_client_l_srv_srv(data, client_l_srv_srv, KDBClient_1);
           break; 

        case 1 :
           func_client_r_srv_lp(data, client_r_srv_lp, KDBClient_1);
           break; 

    default :
      RCLCPP_INFO(KDBClient_1->get_logger(), "string out of range");
  }
  }
rclcpp::shutdown();
return 0;
}
