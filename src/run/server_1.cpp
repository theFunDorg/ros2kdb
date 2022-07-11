
#include <memory>
#include "rclcpp/rclcpp.hpp"
#define KXVER 3
#include "k.h"

#include "racer_interfaces/srv/serve.hpp"

#include "racer_interfaces/srv/level_positions.hpp"

using std::placeholders::_1;
using std::placeholders::_2;
using std::placeholders::_3;
using std::placeholders::_4;
using std::placeholders::_5;
using std::placeholders::_6;
using std::placeholders::_7;
using std::placeholders::_8;
int hndl;
class KDBServer_1 : public rclcpp::Node
{
 public:
     KDBServer_1()
     :Node("KDBServer_1")
     {

         server_l_srv_srv = this->create_service<racer_interfaces::srv::Serve>("l_srv_srv", std::bind(&KDBServer_1::func_l_srv_srv, this, _1, _2));

         server_r_srv_lp = this->create_service<racer_interfaces::srv::LevelPositions>("r_srv_lp", std::bind(&KDBServer_1::func_r_srv_lp, this, _1, _2));

     }
 
 private:

    void func_l_srv_srv(const std::shared_ptr<racer_interfaces::srv::Serve::Request> request,
              std::shared_ptr<racer_interfaces::srv::Serve::Response>      response)
    {   
        K resp=k(hndl,".ros.Serve" ,kj((request->input_a)),kj((request->input_b)),(K)0);
        
    response->output_c=(resp->f);
    }

    void func_r_srv_lp(const std::shared_ptr<racer_interfaces::srv::LevelPositions::Request> request,
              std::shared_ptr<racer_interfaces::srv::LevelPositions::Response>      response)
    {   
        K resp=k(hndl,".ros.levelPositions" ,kh((request->exec)),(K)0);
        
    response->successs=(resp->h);
    }


    rclcpp::Service<racer_interfaces::srv::Serve>::SharedPtr server_l_srv_srv;

    rclcpp::Service<racer_interfaces::srv::LevelPositions>::SharedPtr server_r_srv_lp;

  };
int main(int argc, char **argv)
{
  hndl = khpu("0.0.0.0", 3456,"myusername:mypassword");
  K r = k(hndl,".ros.servInit[]",(K)0);
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<KDBServer_1>());
  rclcpp::shutdown();
}
