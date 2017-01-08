#!/usr/bin/python
import math,scipy.stats
print('%.4f'%scipy.stats.norm.cdf(250, loc=100*2.4, scale=math.sqrt(100)*2.0))
