#!/usr/bin/python
import sys,math
def calcdist(a):
	lat1,lon1,lat2,lon2=map(lambda e:e*math.pi/180,a)
	return 3474.3/2*math.acos( (math.sin(lat1)*math.sin(lat2)+math.cos(lat1)*math.cos(lat2)*math.cos(lon1-lon2)) )

b1,a1=map(float,sys.stdin.readline().split())
b2,a2=map(float,sys.stdin.readline().split())
print(calcdist([a1,b1,a2,b2]))