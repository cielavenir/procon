#!/usr/bin/python
import scipy.stats
print('%.3f'%scipy.stats.norm.cdf(40, loc=30, scale=4))
print('%.3f'%(1-scipy.stats.norm.cdf(21, loc=30, scale=4)))
print('%.3f'%(scipy.stats.norm.cdf(35, loc=30, scale=4)-scipy.stats.norm.cdf(30, loc=30, scale=4)))