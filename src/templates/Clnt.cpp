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
#include "CLNT_PKG/srv/SRV_FILE.hpp"
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


class KDBClient : public rclcpp::Node
{
public:
  KDBClient()
  : Node("kdb_client")
  {
#####FORLOOP
    client_CLIENT_NAME=this->create_client<CLNT_PKG::srv::SRV_NAME>("client_CLIENT_NAME");
######LOOPEND
    timer_ = this->create_wall_timer(0ms, std::bind(&KDBClient::timer_callback, this));
  }

private:
#####FORLOOP
  void func_client_CLIENT_NAME(K data) 
  { 
    auto request = std::make_shared<CLNT_PKG::srv::SRV_NAME::Request>();
      request->avalu = kI(data)[0];
      request->bvalu = kI(data)[1];

      KDB_CLIENT_REQUEST_CONVERTOR

    // Wait for the result.
    using ServiceResponseFuture =
      rclcpp::Client<CLNT_PKG::srv::SRV_NAME>::SharedFuture;
    auto response_received_callback = [this](ServiceResponseFuture future) {
        K resp=kf((future.get())->cvalu);

        K resp=knk(KDB_CLIENT_RESPONSE_CONVERTOR);
        k(hndl,"{.ros.clientResponse[`KDB_SRV_NAME;x]}",resp,(K)0);
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
           func_client_CLIENT_NAME(data);
           break; 
######LOOPEND
       default :
           RCLCPP_INFO(this->get_logger(), "string out of range");
    }
  }
  rclcpp::TimerBase::SharedPtr timer_;
#####FORLOOP
  rclcpp::Client<CLNT_PKG::srv::SRV_NAME>::SharedPtr client_CLIENT_NAME;  
######LOOPEND

};
int main(int argc, char * argv[])
{
#####FORLOOP
  funcVect.push_back ("func_client_CLIENT_NAME");
######LOOPEND

  hndl = khpu("KDB_HOST", PORT,"KDB_UNAME_PWD");
  K r = k(hndl,".ros.clientInit[]",(K)0);

  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<KDBClient>());
  rclcpp::shutdown();
  return 0;
}
