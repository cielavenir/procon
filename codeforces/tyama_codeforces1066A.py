#!/usr/bin/python
import sys
sys.stdin.readline()
for e in sys.stdin:_,v,l,r=map(int,e.split());print(_//v-r//v+(l-1)//v)
