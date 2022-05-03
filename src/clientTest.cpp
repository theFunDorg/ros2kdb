
#include <chrono>
#include <memory>
#include <vector>
#include <cstdlib>
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#define KXVER 3
#include "k.h"

// Adding custom message header files
#include "podracer_interfaces/srv/serve.hpp"


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
    client_serve_kdb=this->create_client<podracer_interfaces::srv::Serve>("kdbFunc");
    client_serve_cpp=this->create_client<podracer_interfaces::srv::Serve>("cppFunc");
    timer_ = this->create_wall_timer(0ms, std::bind(&MinimalClient::timer_callback, this));
  }

private:
  void func_client_serve_kdb(K data) 
  { 
    auto request = std::make_shared<podracer_interfaces::srv::Serve::Request>();
      request->avalu = kI(data)[0];
      request->bvalu = kI(data)[1];
    auto result = client_serve_kdb->async_send_request(request);
    // Wait for the result.
    rclcpp::spin_until_future_complete(this, result);
    K resp=kf(result.get()->cvalu);
    k(hndl,".ros.clientResponse","funcServKDB",resp,(K)0);
  }

  void func_client_serve_cpp(K data) 
  { 
    auto request = std::make_shared<podracer_interfaces::srv::Serve::Request>();
      request->avalu = kI(data)[0];
      request->bvalu = kI(data)[1];
    auto result = client_serve_kdb->async_send_request(request);
    // Wait for the result.
    // if (rclcpp::spin_until_future_complete(this, result) == rclcpp::FutureReturnCode::SUCCESS)
    // {
    //   RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Sum: "); //%ld", result.get()->sum);
    // } else {
    //   RCLCPP_ERROR(rclcpp::get_logger("rclcpp"), "Failed to call service func_client_serve_cpp");
    // }
    // ->cvalu
    K resp=kf(result.get()->cvalu);
    k(hndl,".ros.clientResponse","funcServCPP",resp,(K)0);
  }

  void timer_callback()
  {
    response= k((-hndl), (S) 0); 
    topic=kK(response)[0];
    data=kK(response)[1]; 
    switch( checkString( topic->s , funcVect ) ) {

        case 0 :
           func_client_serve_kdb(data);
           break; 

        case 1 :
           func_client_serve_cpp(data);
           break; 

       default :
           RCLCPP_INFO(this->get_logger(), "string out of range");
    }
  }
  rclcpp::TimerBase::SharedPtr timer_;
  rclcpp::Client<podracer_interfaces::srv::Serve>::SharedPtr client_serve_kdb;  
  rclcpp::Client<podracer_interfaces::srv::Serve>::SharedPtr client_serve_cpp;
};
int main(int argc, char * argv[])
{

  funcVect.push_back ("func_client_serve_kdb");
  funcVect.push_back ("func_client_serve_cpp");

 // // Checking if service is responsive
 // while (!client_serve_kdb->wait_for_service(1s)) {
 //   if (!rclcpp::ok()) {
 //     RCLCPP_ERROR(rclcpp::get_logger("rclcpp"), "Interrupted while waiting for the service. Exiting.");
 //     return 0;
 //   }
 //   RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "service not available, waiting again...");
 // }
//
 // // Checking if service is responsive
 // while (!client_serve_cpp->wait_for_service(1s)) {
 //   if (!rclcpp::ok()) {
 //     RCLCPP_ERROR(rclcpp::get_logger("rclcpp"), "Interrupted while waiting for the service. Exiting.");
 //     return 0;
 //   }
 //   RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "service not available, waiting again...");
 // }

  hndl = - khpu("0.0.0.0", 4567,"myusername:mypassword");
  K r = k(hndl,".ros.clientInit[]",(K)0);
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<MinimalClient>());
  rclcpp::shutdown();
  return 0;
}



//===================================================================================================================================
//===================================================================================================================================
//===================================================================================================================================


//int main(int argc, char **argv)
//{
//  rclcpp::init(argc, argv);
//
//  std::shared_ptr<rclcpp::Node> node = rclcpp::Node::make_shared("add_two_ints_client");
//  rclcpp::Client<example_interfaces::srv::AddTwoInts>::SharedPtr client = node->create_client<example_interfaces::srv::AddTwoInts>("add_two_ints");
//
//
//  // Creating Message Request
//  auto request = std::make_shared<example_interfaces::srv::AddTwoInts::Request>();
//  request->a = atoll(argv[1]);
//  request->b = atoll(argv[2]);
//
//
//  // Checking if service is responsive
//  while (!client->wait_for_service(1s)) {
//    if (!rclcpp::ok()) {
//      // RCLCPP_ERROR(rclcpp::get_logger("rclcpp"), "Interrupted while waiting for the service. Exiting.");
//      return 0;
//    }
//    // RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "service not available, waiting again...");
//  }
//  // define result as auto
//  auto result = client->async_send_request(request);
//
//  // Wait for the result.
//  if (rclcpp::spin_until_future_complete(node, result) == rclcpp::FutureReturnCode::SUCCESS)
//  {
//    // RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Sum: %ld", result.get()->sum);
//  } else {
//    // RCLCPP_ERROR(rclcpp::get_logger("rclcpp"), "Failed to call service add_two_ints");
//  }
//
//  rclcpp::shutdown();
//  return 0;
//}