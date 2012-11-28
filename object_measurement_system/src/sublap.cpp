#include "ros/ros.h"
#include "std_msgs/String.h"

void printMsr;
int main(int argc, char *argv[])
{
	ros::init(argc, argv, "sublap");
	ros::NodeHandle nh;
	ros:::Subscriber msr_sub = ns.subscribe("sublap, 1000", printMsr);
	while(ros::ok())
	{
	}
	return 0;
}
