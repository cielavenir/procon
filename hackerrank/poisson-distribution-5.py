#!/usr/bin/python
import math,scipy.stats
print('%.3f'%scipy.stats.poisson.pmf(2,1.2))
print('%.3f'%scipy.stats.poisson.cdf(2,1.2))
print('%.3f'%scipy.stats.poisson.pmf(5,1.2*10))
print('%.3f'%(1-scipy.stats.poisson.cdf(2,1.2*40)))
