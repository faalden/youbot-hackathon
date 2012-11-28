#!/usr/bin/env python

import roslib; roslib.load_manifest('')
import rospy
import Math
from std_msgs.msg import String


def neardistance(read_sensor):					//suche Geraden anfang
	sensor_value = read_sensor
        old_pos=sensor_value[0]
        for pos in range(1):    
                if sensor_value[pos]<sensor_value[old_pos]:
                        old_pos=sensor_value
	return old_pos
def geraden_lenge(winkel1, entfernung, winkel2, entferung2)	//Berechner Geraden Länge
	return math.asin(winkel1)*entfernung1 -
               math.asin(winkel2)*entfernung2
def gerade_finden(messpunkte[],start)				//
	steigung=messpunkte[start]/messpunkte[start+1]
	for pos in range(start,len(messpunkt))
		if messpunkte[pos-1]/messpunkte[pos] != steigung:
			return pos 
def controll():
	sensor_values=read_sensor()
	neardistance(sensor_values)
	



def talker():
        pub = rospy.Publisher('', Chat)
        rospy.init_node('')

        ch = Chat()

        while not rospy.is_shutdown():

                rospy.loginfo(ch.message)

                pub.publish(ch)
                rospy.sleep(1)

if __name__ == '__main__':
        try:
                talker()
        except rospy.ROSInterruptException:
                pass

