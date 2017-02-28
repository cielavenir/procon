#!/usr/bin/python
import sys
if sys.version_info[0]>=3: raw_input=input

def checkio(x):
	m={'(':')','{':'}','[':']'}
	s=[]
	for e in x:
		if e in'({[':s+=[m[e]]
		if e in')}]'and(not s or s.pop()!=e):return False
	return not s

print ['false','true'][checkio(raw_input())]
