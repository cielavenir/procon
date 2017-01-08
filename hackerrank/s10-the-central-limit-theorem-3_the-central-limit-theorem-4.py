#!/usr/bin/python
import math,scipy.stats
x,y=scipy.stats.norm.interval(0.95, loc=500, scale=80/math.sqrt(100))
print("%.2f\n%.2f"%(x,y))
