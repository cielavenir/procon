#!/usr/bin/python
import sys

if sys.version_info[0]>=3: raw_input=input
while 1:
	enemy_1 = raw_input() # name of enemy 1
	dist_1 = int(raw_input()) # distance to enemy 1
	enemy_2 = raw_input() # name of enemy 2
	dist_2 = int(raw_input()) # distance to enemy 2
	print(enemy_1 if dist_1<dist_2 else enemy_2)