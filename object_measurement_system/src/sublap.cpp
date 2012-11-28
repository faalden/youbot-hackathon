#include "ros/ros.h"
#include "std_msgs/String.h"

void printMsr(const std_msgs::String::ConstPtr& output)
{
	ROS_INFO("Received information: %s", output->data.c_str());
}

int main(int argc, char *argv[])
{
	ros::init(argc, argv, "sublap");
	ros::NodeHandle nh;
	ros:::Subscriber msr_sub = ns.subscribe("sendInf, 1000", printMsr);
	ros::spin();
	/*while(ros::ok())
	{
	}*/
	return 0;
}
