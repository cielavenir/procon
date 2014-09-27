#!/usr/bin/python
import sys
from sklearn import linear_model
import numpy
if sys.version_info[0]>=3: raw_input=input
F,N=map(int,raw_input().split())
factors=[list(map(float,raw_input().split())) for i in range(N)]
target=[]
for i in range(len(factors)): target.append(factors[i].pop())
clf = linear_model.LinearRegression()
clf.fit(factors,target)
for i in range(int(raw_input())):
	print(numpy.dot(clf.coef_,list(map(float,raw_input().split())))+clf.intercept_)