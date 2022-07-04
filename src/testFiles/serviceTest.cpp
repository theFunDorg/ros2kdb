#include <memory>
#include "rclcpp/rclcpp.hpp"
#define KXVER 3
#include "k.h"

#include "podracer_interfaces/srv/serve.hpp"
using std::placeholders::_1;
using std::placeholders::_2;

int hndl;

class MinimalService : public rclcpp::Node
{
 public:
     MinimalService()
     :Node("minimal_service")
     {
         FuncOne = this->create_service<podracer_interfaces::srv::Serve>("kdbFunc", std::bind(&MinimalService::firstFunc, this, _1, _2));
         FuncTwo = this->create_service<podracer_interfaces::srv::Serve>("cppFunc", std::bind(&MinimalService::secondFunc, this, _1, _2));
     }
 
 private:

    void firstFunc(const std::shared_ptr<podracer_interfaces::srv::Serve::Request> request,
              std::shared_ptr<podracer_interfaces::srv::Serve::Response>      response)
    {   
        K resp=k(hndl,".ros.funcOne",ki((request->avalu)), ki((request->bvalu)),(K)0);
        response->cvalu=(resp->f);
    }

    void secondFunc(const std::shared_ptr<podracer_interfaces::srv::Serve::Request> request,
              std::shared_ptr<podracer_interfaces::srv::Serve::Response>      response)
    {
      response->cvalu = request->avalu + request->bvalu;
    }
    rclcpp::Service<podracer_interfaces::srv::Serve>::SharedPtr FuncOne;
    rclcpp::Service<podracer_interfaces::srv::Serve>::SharedPtr FuncTwo;
  };


int main(int argc, char **argv)
{
  hndl = khpu("0.0.0.0", 3456,"myusername:mypassword");
  K r = k(hndl,".ros.servInit[]",(K)0);

  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<MinimalService>());
  rclcpp::shutdown();
}