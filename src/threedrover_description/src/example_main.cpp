#include <ros/ros.h>

#include "example_node.hpp"

const std::string node_name = "NODE1";

int main(int argc, char* argv[]) {

    // Initialise ROS node.
    ros::init(argc, argv, node_name);

    // Initialise handle for current ROS node.
    ros::NodeHandle nh;

    // Pass handle to a class to be encapsulated.
    ex::ExampleNode e(std::make_unique<ros::NodeHandle>(nh));

	int i = 0;

    // Spin the node.
    while (ros::ok()) {
        // Do something with e if you wish.
	if(i < 1000) {
		e.do_something(ex::ExampleNode::Mode::Nothing);
	}else {
		e.do_something(ex::ExampleNode::Mode::Nothing);
	}
	i++;
        // Spin once.
        ros::spinOnce();
    }

    return EXIT_SUCCESS;
}
