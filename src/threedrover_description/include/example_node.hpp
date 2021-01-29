#ifndef EXAMPLE_NODE_HPP_
#define EXAMPLE_NODE_HPP_

#include <ros/ros.h>
#include <std_msgs/Float64.h>

namespace ex {

class ExampleNode {
   public:
	enum Mode {Nothing, TurnLeft, TurnRight, Forward, Backward};
    /**
     * ExampleNode constructor should initialise all subscribers and publishers
     * associated with the given node.
     * 
     * Initialisation of subscribers may be paired with a callback method.
     */
    ExampleNode(std::unique_ptr<ros::NodeHandle> nh);

    /**
     * ExampleNode destructor
     */
    ~ExampleNode();

    /**
     * ADD METHODS HERE
     * 
     * Methods for doing something every ROS spin or timely interval.
     */
    void do_something(ex::ExampleNode::Mode mode);

    /**
     * ADD CALLBACKS HERE
     * 
     * Callback methods runs when the associated subscriber receives a message.
     */
    void sub_callback(const std_msgs::Float64& msg);


   private:
    /**
     * ADD HELPER METHODS HERE
     */
    void helper_function();

   private:
    ros::NodeHandle nh;

    /* ADD PUBLISHERS HERE */
    ros::Publisher pubFL;
    ros::Publisher pubFR;
    ros::Publisher pubBL;
    ros::Publisher pubBR;

    /* ADD SUBSCRIBERS HERE */
    ros::Subscriber sub;

    /* ADD YOUR OWN PRIVATE VARIABLES */
    std_msgs::Float64 data;

};
}  // namespace ex

#endif  // EXAMPLE_NODE_HPP_
