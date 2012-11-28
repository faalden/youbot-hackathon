#include "ros/ros.h"
#include "std_msgs/String.h"
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
	ros::init(argc, argv, "pubrob");
	ros::NodeHandle nh;
	ros::Publisher msr_pub = n.advertise<std_msgs::String>("pubrob",1000);
	ros::Rate ls(200);

	while(ros::ok())
	{
		msr_pub.publish("Checking values ...");
		ROS_INFO("Information sent.");
		ls.sleep(200);
	}
	return 0;
}
