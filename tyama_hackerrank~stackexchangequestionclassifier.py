#!/usr/bin/python
#coding:utf-8
import json,sys
from sklearn.svm import LinearSVC
#from sklearn.ensemble import RandomForestClassifier
from sklearn.feature_extraction.text import HashingVectorizer
if sys.version_info[0]>=3: raw_input=input
transformer=HashingVectorizer(stop_words='english')

_train=[]
train_label=[]
f=open('training.json')
for i in range(int(f.readline())):
	h=json.loads(f.readline())
	_train.append(h['question']+"\r\n"+h['excerpt'])
	train_label.append(h['topic'])
f.close()
train = transformer.fit_transform(_train)
svm=LinearSVC()
svm.fit(train,train_label)

_test=[]
for i in range(int(raw_input())):
	h=json.loads(raw_input())
	_test.append(h['question']+"\r\n"+h['excerpt'])
test = transformer.transform(_test)
test_label=svm.predict(test)
for e in test_label: print(e)