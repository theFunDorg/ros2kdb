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
#include "CLNT_PKG/srv/HEADER_NAME.hpp"
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

#####FORLOOP
  void func_client_CLIENT_NAME(K data, auto client, auto node) 
  { 
    auto request = std::make_shared<CLNT_PKG::srv::SRV_NAME::Request>();
      KDB_CLIENT_REQUEST_CONVERTOR
    auto result = client->async_send_request(request);
    rclcpp::spin_until_future_complete(node, result);
    // Wait for the result.
    K resp=knk(KDB_CLIENT_RESPONSE_CONVERTOR);
    k(hndl,"{.ros.clientResponse[`CLIENT_NAME;x]}",resp,(K)0);
  }
######LOOPEND

int main(int argc, char **argv)
  {
  // Add match strings for service names  
#####FORLOOP
  funcVect.push_back ("CLIENT_NAME");
######LOOPEND

  hndl = - khpu("KDB_HOST", PORT,"KDB_UNAME_PWD");
  K r = k(hndl,".ros.clientInit[]",(K)0);

  rclcpp::init(argc, argv);

  std::shared_ptr<rclcpp::Node> NODE_NAME = rclcpp::Node::make_shared("NODE_NAME");
#####FORLOOP
  rclcpp::Client<CLNT_PKG::srv::SRV_NAME>::SharedPtr client_CLIENT_NAME;  
    client_CLIENT_NAME=NODE_NAME->create_client<CLNT_PKG::srv::SRV_NAME>("CLIENT_NAME");
######LOOPEND

  // Loop to take in KDB+ data
  while (true) {
    response= k((-hndl), (S) 0); 
    topic=kK(response)[0];
    data=kK(response)[1]; 
    switch( checkString( topic->s , funcVect ) ) {
#####FORLOOP
        case INDEX :
           func_client_CLIENT_NAME(data, client_CLIENT_NAME, NODE_NAME);
           break; 
######LOOPEND
    default :
      RCLCPP_INFO(NODE_NAME->get_logger(), "string out of range");
  }
  }
rclcpp::shutdown();
return 0;
}
