#!/usr/bin/python
import math,scipy.stats
print("%.4f"%(scipy.stats.norm.cdf(510, loc=500, scale=80/math.sqrt(100))-scipy.stats.norm.cdf(490, loc=500, scale=80/math.sqrt(100))))
