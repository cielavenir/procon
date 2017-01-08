#!/usr/bin/python
import scipy.stats
print('%.3f'%scipy.stats.norm.cdf(19.5, loc=20, scale=2))
print('%.3f'%(scipy.stats.norm.cdf(22, loc=20, scale=2)-scipy.stats.norm.cdf(20, loc=20, scale=2)))
