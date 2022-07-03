
#include <memory>
#include "rclcpp/rclcpp.hpp"
#define KXVER 3
#include "k.h"

#include "racer_interfaces/srv/serve.hpp"

#include "racer_interfaces/srv/edf_state.hpp"

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
class KDBService : public rclcpp::Node
{
 public:
     KDBService()
     :Node("kdb_service")
     {

         server_l_srv_srv = this->create_service<racer_interfaces::srv::Serve>("kdbFunc", std::bind(&KDBService::func_l_srv_srv, this, _1, _2));

         server_l_srv_es = this->create_service<racer_interfaces::srv::EdfState>("kdbFunc", std::bind(&KDBService::func_l_srv_es, this, _1, _2));

         server_r_srv_lp = this->create_service<racer_interfaces::srv::LevelPositions>("kdbFunc", std::bind(&KDBService::func_r_srv_lp, this, _1, _2));

     }
 
 private:

    void func_l_srv_srv(const std::shared_ptr<racer_interfaces::srv::Serve::Request> request,
              std::shared_ptr<racer_interfaces::srv::Serve::Response>      response)
    {   
        K resp=k(hndl,".ros.Serve" ,ki((request->input_a)),ki((request->input_b)),(K)0);
        
    response->output_c=(resp->f);
    }

    void func_l_srv_es(const std::shared_ptr<racer_interfaces::srv::EdfState::Request> request,
              std::shared_ptr<racer_interfaces::srv::EdfState::Response>      response)
    {   
        K resp=k(hndl,".ros.edfState" ,kS((request->action)),(K)0);
        
    response->successs=(resp->f);
    }

    void func_r_srv_lp(const std::shared_ptr<racer_interfaces::srv::LevelPositions::Request> request,
              std::shared_ptr<racer_interfaces::srv::LevelPositions::Response>      response)
    {   
        K resp=k(hndl,".ros.levelPositions" ,kb((request->exec)),(K)0);
        
    response->successs=(resp->f);
    }


    rclcpp::Service<racer_interfaces::srv::Serve>::SharedPtr server_l_srv_srv;

    rclcpp::Service<racer_interfaces::srv::EdfState>::SharedPtr server_l_srv_es;

    rclcpp::Service<racer_interfaces::srv::LevelPositions>::SharedPtr server_r_srv_lp;

  };
int main(int argc, char **argv)
{
  hndl = khpu("0.0.0.0", 3456,"myusername:mypassword");
  K r = k(hndl,".ros.servInit[]",(K)0);
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<KDBService>());
  rclcpp::shutdown();
}
