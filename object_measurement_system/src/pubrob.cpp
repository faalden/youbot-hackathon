#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sstream>
#define MM 1000				// milli metres

double getNextValue();
char *dvalToString(const double val);

double getNextValue()
{
	double x = 20.5;
	return x;
}

char *dvalToString(const double val)
{
	double buf = val;
	char str[7];
	int status = 2, div = 10, strp = 0;

	if(val >= 100)
		return (char *)"-1";
	for(;;)
	{
		if(status == 2)
		{
			str[strp] = '0' + (char)(((int)buf) / div);
			ROS_INFO("%c", str[strp]);
			buf -= (str[strp] - '0') * div;
			div /= 10;
			if(div < 1) --status;
		}
		else if(status == 0)
		{
			if()
			str[strp] = '0' + ((char)(buf *= 10));
			ROS_INFO("%c", str[strp]);
			div *= 10;
			if(div == MM)
				return str;
		}
		else
		{
			str[strp] = '.';
			ROS_INFO("%c", str[strp]);
			div = 10;
			--status;
		}
		strp++;
	}
}

int main(int argc, char *argv[])
{
	ros::init(argc, argv, "pubrob");
	ros::NodeHandle nh;
	ros::Publisher msr_pub = nh.advertise<std_msgs::String>("pubrob",1000);
	ros::Rate ls(200);

	std_msgs::String msr_msg;
	std::stringstream convs;
	ROS_INFO("Check ros-loop");
	while(ros::ok())
	{
		ROS_INFO("Check dvalToString");
		convs << dvalToString(getNextValue()) << "m";
		msr_msg.data = convs.str();
		msr_pub.publish(msr_msg);
		ROS_INFO("Information published: %s", msr_msg);
		ls.sleep();
	}
	return 0;
}
