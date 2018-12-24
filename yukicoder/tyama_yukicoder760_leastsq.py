#!/usr/bin/python
from numpy import array,linalg
from scipy import optimize
import sys,math

def thirdPoint(a):
	xdiff=a[1][0]-a[0][0]
	ydiff=a[1][1]-a[0][1]
	return [a[1][0]-ydiff,a[1][1]+xdiff]

#Least squares method with scipy.optimize
def fit_func(orig_parameter):
	def f(parameter, xdata, ydata):
		# ydata = final * interminv * xdata
		old_theta = orig_parameter[2]*math.pi/180
		a = parameter[0]
		b = parameter[1]
		new_theta = parameter[2]*math.pi/180
		# transform x
		intermidiate = array([[math.cos(old_theta),-math.sin(old_theta),orig_parameter[0]],[math.sin(old_theta),math.cos(old_theta),orig_parameter[1]],[0,0,1]])
		final = array([[math.cos(new_theta),-math.sin(new_theta),a],[math.sin(new_theta),math.cos(new_theta),b],[0,0,1]])
		res = []
		resultdata = []
		for (x,y) in zip(xdata,ydata):
			r = intermidiate.dot(linalg.inv(final).dot([x[0],x[1],1]))
			resultdata.append((r[0],r[1]))
			res.append(math.hypot(y[0]-r[0],y[1]-r[1]))
		return res
	return f

N=2
orig_parameter = list(map(float,sys.stdin.readline().split()))
xdata = [list(map(float,sys.stdin.readline().split())) for _ in range(N)]
ydata = [list(map(float,sys.stdin.readline().split())) for _ in range(N)]

result0 = optimize.leastsq(fit_func(orig_parameter),orig_parameter,args=(xdata+[thirdPoint(xdata)],ydata+[thirdPoint(ydata)]))
#practically x_scale/xtol/gtol/ftol hacks should not be required.
#eps = 2.22044605e-16
#result = optimize.least_squares(fit_func(orig_parameter),result0[0],args=(xdata+[thirdPoint(xdata)],ydata+[thirdPoint(ydata)]),method='trf',max_nfev=700,jac='3-point',x_scale='jac',xtol=eps,gtol=eps,ftol=eps)
result = optimize.least_squares(fit_func(orig_parameter),result0[0],args=(xdata+[thirdPoint(xdata)],ydata+[thirdPoint(ydata)]),method='trf')
print(' '.join('%.12f'%e for e in result.x))
print(result)