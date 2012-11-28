#!/usr/bin/env python

import roslib; roslib.load_manifest('object_measurement_system')
import rospy
import math
from sensor_msgs.msg import LaserScan
from std_msgs.msg import String

def geraden_lenge(winkel1, entfernung1, winkel2, entfernung2):	#Berechner Geraden Lenge
	return math.asin(winkel1)*entfernung1 - math.asin(winkel2)*entfernung2

def gerade_finden(sensor_values,start):				#Ubergebe Geraden anfang, return geraden Ende 
	steigung=sensor_values[start]/sensor_values[start+1]
	for pos in range(start,len(sensor_values)):
		if sensor_values[pos-1]/sensor_values[pos] != steigung:
			return pos 

def controll(sensor_values):
	pos1=neardistance(sensor_values)
	pos2=gerade_finden(sensor_values,pos1)
	lenge=geraden_lenge(radToDeg(pos1),pos1,radToDeg(pos2),pos2)
	print lenge	
	return lenge

def radToDeg(pos):						#Rechne Lesersensor Winkel in DEG Winkel um				
	return pos*2*math.pi

def callback(data):
	controll(data.ranges)

def readLaserSensor():
        rospy.init_node('listener', anonymous=True)
	rospy.Subscriber("/scan_front", LaserScan, callback)
        rospy.spin()
	
def neardistance(sensor_values):				#suche Gerade anfang
        old_pos=0
        for pos in range(1,len(sensor_values)):    
                if sensor_values[pos]<sensor_values[old_pos]:
                        old_pos=pos
	return old_pos

if __name__ == '__main__':
        try:
               	readLaserSensor()
        except rospy.ROSInterruptException:
                pass

