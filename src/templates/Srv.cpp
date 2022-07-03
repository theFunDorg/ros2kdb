#include <memory>
#include "rclcpp/rclcpp.hpp"
#define KXVER 3
#include "k.h"

#####FORLOOP
#include "SRV_PKG/srv/HEADER_NAME.hpp"
#####LOOPEND

using std::placeholders::_1;
using std::placeholders::_2;
using std::placeholders::_3;
using std::placeholders::_4;
using std::placeholders::_5;
using std::placeholders::_6;
using std::placeholders::_7;
using std::placeholders::_8;


int hndl;

class KDBServer : public rclcpp::Node
{
 public:
     KDBServer()
     :Node("kdb_service")
     {
#####FORLOOP
         server_SERVER_NAME = this->create_service<SRV_PKG::srv::SRV_FILE>("kdbFunc", std::bind(&KDBServer::func_SERVER_NAME, this, _1, _2));
#####LOOPEND
     }
 
 private:
#####FORLOOP
    void func_SERVER_NAME(const std::shared_ptr<SRV_PKG::srv::SRV_FILE::Request> request,
              std::shared_ptr<SRV_PKG::srv::SRV_FILE::Response>      response)
    {   
        K resp=k(hndl,"KDB_FUNC_NAME" KDB_REQUEST_CONVERTOR,(K)0);
        KDB_RESPONSE_CONVERTOR;
    }
#####LOOPEND

#####FORLOOP
    rclcpp::Service<SRV_PKG::srv::SRV_FILE>::SharedPtr server_SERVER_NAME;
#####LOOPEND
  };


int main(int argc, char **argv)
{
  hndl = khpu("KDB_HOST", PORT,"KDB_UNAME_PWD");
  K r = k(hndl,".ros.servInit[]",(K)0);

  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<KDBServer>());
  rclcpp::shutdown();
}