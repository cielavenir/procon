#!/usr/bin/python
#coding:utf-8
import json,sys
from sklearn.svm import LinearSVC
#from sklearn.ensemble import RandomForestClassifier
#from sklearn.neighbors import KNeighborsClassifier
#from sklearn.tree import DecisionTreeClassifier
#from sklearn.linear_model import SGDClassifier,RidgeClassifier
from sklearn.feature_extraction import DictVectorizer
if sys.version_info[0]>=3: raw_input=input
transformer=DictVectorizer()

_train=[]
train_label=[]
f=open('training.json')
for i in range(int(f.readline())):
	h=json.loads(f.readline())
	train_label.append(h['category'])
	del h['category']
	_train.append(h)
f.close()
train = transformer.fit_transform(_train)
svm=LinearSVC()
svm.fit(train,train_label)

_test=[]
for i in range(int(raw_input())):
	h=json.loads(raw_input())
	_test.append(h)
test = transformer.transform(_test)
test_label=svm.predict(test)
for e in test_label: print(e)