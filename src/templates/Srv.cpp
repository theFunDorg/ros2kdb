#include <memory>
#include "rclcpp/rclcpp.hpp"
#define KXVER 3
#include "k.h"

#####FORLOOP
#include "podracer_interfaces/srv/serve.hpp"
#####LOOPEND

using std::placeholders::_1;
using std::placeholders::_2;

int hndl;

class MinimalService : public rclcpp::Node
{
 public:
     MinimalService()
     :Node("minimal_service")
     {
#####FORLOOP
         FuncOne = this->create_service<podracer_interfaces::srv::Serve>("kdbFunc", std::bind(&MinimalService::firstFunc, this, _1, _2));
#####LOOPEND
     }
 
 private:
#####FORLOOP
    void firstFunc(const std::shared_ptr<podracer_interfaces::srv::Serve::Request> request,
              std::shared_ptr<podracer_interfaces::srv::Serve::Response>      response)
    {   
        K resp=k(hndl,".ros.funcOne",ki( (request->avalu)), ki( (request->bvalu)),(K)0);
        response->cvalu=(resp->f);
    }
#####LOOPEND

#####FORLOOP
    rclcpp::Service<podracer_interfaces::srv::Serve>::SharedPtr FuncOne;
#####LOOPEND
  };


int main(int argc, char **argv)
{
  hndl = khpu("0.0.0.0", 3456,"myusername:mypassword");
  K r = k(hndl,".ros.servInit[]",(K)0);

  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<MinimalService>());
  rclcpp::shutdown();
}