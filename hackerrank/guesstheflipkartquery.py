#!/usr/bin/python
#coding:utf-8
import sys
from sklearn.svm import LinearSVC
#from sklearn.ensemble import RandomForestClassifier
from sklearn.feature_extraction.text import HashingVectorizer
if sys.version_info[0]>=3: raw_input=input
transformer=HashingVectorizer(stop_words='english')

x=['axe deo','best-seller books','calvin klein','camcorder','camera','chemistry','chromebook','c programming','data structures algorithms','dell laptops','dslr canon','mathematics','nike-deodrant','physics','sony cybershot','spoken english','timex watch','titan watch','tommy watch','written english']

_train=[]
train_label=[]
f=open('training.txt')
for i in range(int(f.readline())):
	s=f.readline().rstrip()
	idx=s.find("\t")
	_train.append(s[:idx])
	train_label.append(x.index(s[idx+1:]))
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
for e in test_label: print(x[e])