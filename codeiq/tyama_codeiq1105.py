#!/usr/bin/python
#coding:utf-8

#提出言語：Python2 (3でも実行できるが、対象外であるため)

for i in range(5,8):
	for j in range(i): print('*'*(j+1)+' '*(i-j-1)+'*'*(i-j)+' '*(j))
	for j in range(i): print(' '*(i-j-1)+'*'*(j+1)+' '*(j)+'*'*(i-j))