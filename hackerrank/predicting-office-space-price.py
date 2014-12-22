#!/usr/bin/python
import sys,itertools
from sklearn.linear_model import LinearRegression
from sklearn.svm import SVR
import numpy
if sys.version_info[0]>=3: raw_input=input

F,N=map(int,raw_input().split())
factors=[list(map(float,raw_input().split())) for i in range(N)]
target=[]
for i in range(len(factors)): target.append(factors[i].pop()**0.5)
factors=[list(itertools.chain.from_iterable((e,e**2,e**3) for e in row)) for row in factors]
clf = LinearRegression()
clf.fit(factors,target)
test=[list(map(float,raw_input().split())) for i in range(int(raw_input()))]
test=[list(itertools.chain.from_iterable((e,e**2,e**3) for e in row)) for row in test]
#for e in test: print(numpy.dot(clf.coef_,e)+clf.intercept_)
for e in clf.predict(test): print(e**2)