#include "example_node.hpp"


ex::ExampleNode::ExampleNode(std::unique_ptr<ros::NodeHandle> nh) {
    pubFL = nh->advertise<std_msgs::Float64>("/owr_rover/wheel_FL_Vel_controller/command", 1000);
    pubFR = nh->advertise<std_msgs::Float64>("/owr_rover/wheel_FR_Vel_controller/command", 1000);
    pubBL = nh->advertise<std_msgs::Float64>("/owr_rover/wheel_BL_Vel_controller/command", 1000);
    pubBR = nh->advertise<std_msgs::Float64>("/owr_rover/wheel_BR_Vel_controller/command", 1000);
}

ex::ExampleNode::~ExampleNode() {}

void ex::ExampleNode::do_something(Mode mode) {
    // DO SOMETHING
    std_msgs::Float64 msg;
	if(mode == ex::ExampleNode::Mode::Nothing) {
		msg.data = 0;
  		pubFL.publish(msg);
 		pubBL.publish(msg);
  		pubFR.publish(msg);
 		pubBR.publish(msg);
   		std::cout << "Stopped" << std::endl;
	}
	if(mode == ex::ExampleNode::Mode::Forward) {
		msg.data = 0.5;
  		pubFL.publish(msg);
 		pubBL.publish(msg);
  		pubFR.publish(msg);
 		pubBR.publish(msg);
   		std::cout << "Going Forward" << std::endl;
	}
	if(mode == ex::ExampleNode::Mode::Backward) {
		msg.data = -0.5;
  		pubFL.publish(msg);
 		pubBL.publish(msg);
  		pubFR.publish(msg);
 		pubBR.publish(msg);
   		std::cout << "Going Backward" << std::endl;
	}
	if(mode == ex::ExampleNode::Mode::TurnLeft) {
		msg.data = 3;
  		pubFL.publish(msg);
 		pubBL.publish(msg);
		msg.data = -3;
  		pubFR.publish(msg);
 		pubBR.publish(msg);
   		std::cout << "Turning Left" << std::endl;
	}
	if(mode == ex::ExampleNode::Mode::TurnRight) {
		msg.data = -3;
  		pubFL.publish(msg);
 		pubBL.publish(msg);
		msg.data = 3;
  		pubFR.publish(msg);
 		pubBR.publish(msg);
   		std::cout << "Turning Right" << std::endl;
	}
}

void ex::ExampleNode::sub_callback(const std_msgs::Float64& msg) {
    // DO SOMETHING
    std::cout << msg.data << std::endl;
}

void ex::ExampleNode::helper_function() {
    // DO SOMETHING
}
