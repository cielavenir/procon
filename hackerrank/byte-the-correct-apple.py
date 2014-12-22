#!/usr/bin/python
#coding:utf-8
import sys
from sklearn.svm import LinearSVC
#from sklearn.ensemble import RandomForestClassifier
from sklearn.feature_extraction.text import HashingVectorizer
if sys.version_info[0]>=3: raw_input=input
transformer=HashingVectorizer(stop_words='english')

_train=[]
train_label=[]
f=open('apple-computers.txt')
try:
	while True:
		s=f.readline()
		if not s: break
		s=s.rstrip()
		if len(s)<100: continue
		_train.append(s)
		train_label.append(1)
except EOFError:
	pass
f.close()
f=open('apple-fruit.txt')
try:
	while True:
		s=f.readline()
		if not s: break
		s=s.rstrip()
		if len(s)<100: continue
		_train.append(s)
		train_label.append(2)
except EOFError:
	pass
f.close()
train = transformer.fit_transform(_train)
svm=LinearSVC()
svm.fit(train,train_label)

_test=[]
for i in range(int(raw_input())):
	s=raw_input().rstrip()
	_test.append(s)
test = transformer.transform(_test)
test_label=svm.predict(test)
for e in test_label: print('computer-company' if e==1 else 'fruit')