#!/usr/bin/python
import sys
if sys.version_info[0]>=3: raw_input=input

def zeller(_y,m,d):
	m+=1
	if m<4:_y-=1;m+=12
	y=_y//100;z=_y%100
	return (5*y+z+y//4+z//4+13*m//5+d-1)%7

M,D,Y=map(int,raw_input().split())
print(['SUNDAY','MONDAY','TUESDAY','WEDNESDAY','THURSDAY','FRIDAY','SATURDAY'][zeller(Y,M,D)])