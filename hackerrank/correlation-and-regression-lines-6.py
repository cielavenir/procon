#!/usr/bin/python
import scipy.stats
x,y=scipy.stats.pearsonr([15,12,8,8,7,7,7,6,5,3],[10,25,17,11,13,17,20,13,9,15])
print('%.3f'%x)