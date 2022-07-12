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

using namespace std::chrono_literals;

int checkString (std::string inp, std::vector<std::string> vct)
{
  for(unsigned int i = 0; i < vct.size(); i++) {
      if(vct[i]==inp){
          return (int) i;
      }
  }
  return 999;
};


  void func_client_l_srv_srv(K data, auto client, auto node) 
  { 
    auto request = std::make_shared<racer_interfaces::srv::Serve::Request>();
      request->input_a = kI(data)[0];
      request->input_b = kI(data)[1];
    auto result = client->async_send_request(request);
    rclcpp::spin_until_future_complete(node, result);
    // Wait for the result.  
    K resp=kf( (result.get())->output_c );
    k(hndl,"{.ros.clientResponse[`funcServKDB;x]}",resp,(K)0);    
  }

//  void func_client_r_srv_lp(K data, auto client, auto node) 
//  { 
//    auto request = std::make_shared<racer_interfaces::srv::Serve::Request>();
//      request->exec = kH(data)[0];
//    K result = client->async_send_request(request);
//    rclcpp::spin_until_future_complete(node, result);
//    // Wait for the result.  
//    K resp=kh((result.get())->successs);
//    k(hndl,"{.ros.clientResponse[`funcServKDB;x]}",resp,(K)0);    
//  }



int main(int argc, char **argv)
  {
  // Add match strings for service names  
  funcVect.push_back ("l_srv_srv");
  funcVect.push_back ("r_srv_lp");

  // Connect to KDB
  hndl = - khpu("0.0.0.0", 4567,"myusername:mypassword");
  K r = k(hndl,".ros.clientInit[]",(K)0);

  // Initialise ROS2 and ROS2 node
  rclcpp::init(argc, argv);
  std::shared_ptr<rclcpp::Node> KDBClient = rclcpp::Node::make_shared("KDBClient");

  // Create clients and create shared pointers to 
  rclcpp::Client<racer_interfaces::srv::Serve>::SharedPtr client_l_srv_srv;  
  rclcpp::Client<racer_interfaces::srv::LevelPositions>::SharedPtr client_r_srv_lp;  
  client_l_srv_srv=KDBClient->create_client<racer_interfaces::srv::Serve>("l_srv_srv");
  client_r_srv_lp=KDBClient->create_client<racer_interfaces::srv::LevelPositions>("r_srv_lp");


  // Loop to take in KDB+ data
  while (true) {
    response= k((-hndl), (S) 0); 
    topic=kK(response)[0];
    data=kK(response)[1]; 
    switch( checkString( topic->s , funcVect ) ) {

        case 0 :
           func_client_l_srv_srv(data, client_l_srv_srv, KDBClient);
           break; 

//        case 1 :
//           func_client_r_srv_lp(data, client_r_srv_lp, KDBClient);
//           break; 

       default :
           RCLCPP_INFO(KDBClient->get_logger(), "string out of range");
    }
    }
  rclcpp::shutdown();
  return 0;
  }