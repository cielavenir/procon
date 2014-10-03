#!/usr/bin/python
#coding:utf-8
import sys
#from sklearn.svm import LinearSVC #SVM cannot be used somehow.
from sklearn.ensemble import RandomForestClassifier
from sklearn.feature_extraction import DictVectorizer
if sys.version_info[0]>=3: raw_input=input
transformer=DictVectorizer()

_train=[]
train_label=[]
n,m=[int(e) for e in raw_input().split()]
for i in range(n):
	a=raw_input().split()
	a.pop(0)
	train_label.append(int(a[0]))
	a.pop(0)
	_train.append({int(e[0]):float(e[1]) for e in [x.split(':') for x in a]})
train = transformer.fit_transform(_train).toarray()
svm=RandomForestClassifier()
svm.fit(train,train_label)

test_name=[]
_test=[]
for i in range(int(raw_input())):
	a=raw_input().split()
	test_name.append(a[0])
	a.pop(0)
	_test.append({int(e[0]):float(e[1]) for e in [x.split(':') for x in a]})
test = transformer.transform(_test).toarray()
test_label=svm.predict(test)
for x,y in zip(test_name,test_label): print(x+' %+d'%(y,))