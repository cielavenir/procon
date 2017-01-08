#!/usr/bin/python
import scipy.stats
print('%.2f'%(100*(1-scipy.stats.norm.cdf(80, loc=70, scale=10))))
print('%.2f'%(100*(1-scipy.stats.norm.cdf(60, loc=70, scale=10))))
print('%.2f'%(100*scipy.stats.norm.cdf(60, loc=70, scale=10)))
