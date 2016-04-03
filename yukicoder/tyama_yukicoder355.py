#!/usr/bin/python
#coding:utf-8
from collections import Counter
import itertools,random

digits=4
#mode='mastermind'
mode='hitandblow'

def hit_and_blow(a,b):
	hit=sum(a[i]==b[i] for i in range(digits))
	if mode=='mastermind':
		#mastermind allows duplication (slow)
		ca=Counter(a)
		cb=Counter(b)
		blow=sum(min(0 if k not in cb else cb[k],v) for k,v in ca.items())
	else:
		blow=len(a)+len(b)-len(set(iter(a+b)))
	return (hit,blow-hit)

def minimax(e):
	h={}
	for f in lst:
		x=hit_and_blow(e,f)
		if x not in h: h[x]=0
		h[x]+=1
	return (max(h.values()),e)

def genlist():
	if mode=='mastermind':
		return list(''.join(e) for e in itertools.product(iter('123456'),repeat=digits))
	else:
		return list(''.join(e) for e in itertools.permutations(iter('0123456789'),digits))

def checkio(data):
	global lst
	if len(data)==0:
		lst=genlist()
		if mode=='mastermind': return '1122'
		else: return '0123'
	last=data[-1].split()
	hit=int(last[1][0])
	blow=int(last[1][2])
	last=last[0]
	for i in range(len(lst)-1,-1,-1):
		if hit_and_blow(lst[i],last)!=(hit,blow): lst.pop(i)
	return min(minimax(e) for e in lst)[1]
	#return min(minimax(e) for e in lst)[1] # こちらの評価関数を使うとクエリ数を削減できるがTLE
	return random.choice(lst)

if False:
	def check_solution(func, goal):
		recent = []
		for step in range(7): # not 8; assessment function installed.
			user_result = func(recent)
			bulls, cows = hit_and_blow(user_result,goal)
			recent.append("{0} {1}B{2}C".format(user_result, bulls, cows))
			if bulls == 4:
				print("{0} Win with {1} steps.".format(goal, step + 1))
				return True
		print("{0} Fail.".format(goal))
		return False
	if mode=='mastermind':
		assert check_solution(checkio, "2566"), "2566"
	if mode=='hitandblow':
		assert check_solution(checkio, "1234"), "1234"
		assert check_solution(checkio, "6130"), "6130"
		assert check_solution(checkio, "0317"), "0317"
		assert check_solution(checkio, "9876"), "9876"
		assert check_solution(checkio, "7280"), "7280"
else:
	import sys
	if sys.version_info[0]>=3: raw_input=input
	q=[]
	while True:
		s=checkio(q)
		print(' '.join(s))
		sys.stdout.flush()
		t=raw_input().strip()
		if t=='4 0':break
		q.append(s+' '+'H'.join(t.split()))