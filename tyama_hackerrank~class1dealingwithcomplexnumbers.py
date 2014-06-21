#!/usr/bin/python
import sys
if sys.version_info[0]>=3: raw_input=input

def output(c):
	s=''
	if c.real: s+='%.2f'%c.real
	if c.imag:
		if c.real:
			s+=(' - ' if c.imag<0 else ' + ')+'%.2fi'%abs(c.imag)
		else:
			s+='%.2fi'%c.imag
	print(s if s else '0.00')

c,d=[complex(*map(float,raw_input().split())) for i in range(2)]
output(c+d)
output(c-d)
output(c*d)
output(c/d)
output(abs(c))
output(abs(d))