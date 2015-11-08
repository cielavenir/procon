#!/usr/bin/python
import random,scipy.stats

c=70
N=100
x=[c*i for i in range(N)]
y=[]
for i in range(N):
	y.append((-3*x[i]-8 + 0)/4.0 + (2700 if i%2==1 else 0))

slope, intercept, r_value, p_value, std_err = scipy.stats.linregress(x,y)
print('%.3f %.3f'%(slope,intercept))
slope, intercept, r_value, p_value, std_err = scipy.stats.linregress(y,x)
print('%.3f %.3f'%(slope,intercept))

# y = -0.75x-2.00
# x = -0.75y-1.75

a,b = scipy.stats.pearsonr(x,y)
print('%.2f'%(a))