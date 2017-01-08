#!/usr/bin/ruby
import math,scipy.stats
print('%.3f'%scipy.stats.poisson.pmf(0,3))
#print('%.3f'%(1-2*scipy.stats.poisson.pmf(0,3)*scipy.stats.poisson.pmf(1,3)-scipy.stats.poisson.pmf(0,3)**2))
print('%.3f'%(1-scipy.stats.poisson.cdf(1,3*2)))
