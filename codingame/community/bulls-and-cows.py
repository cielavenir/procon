#!/usr/bin/python
from collections import Counter
import itertools,random

digits=4
mode='mastermind'
#mode='hitandblow'

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
		return list(''.join(e) for e in itertools.product(iter('0123456789'),repeat=digits))
	else:
		return list(''.join(e) for e in itertools.permutations(iter('0123456789'),digits))

def checkio(data):
	global lst
	if len(data)==0:
		lst=genlist()
		if mode=='mastermind': return '1122'
		else: return '0123'
	last=data[-1].split()
	hit=int(last[1])
	blow=int(last[2])
	last=last[0]
	for i in range(len(lst)-1,-1,-1):
		if hit_and_blow(lst[i],last)!=(hit,blow): lst.pop(i)
	#return min(minimax(e) for e in lst)[1]
	#return random.choice(lst)

n=int(raw_input())
recent=[]
checkio(recent)
for _ in range(n):
	recent.append(raw_input())
	checkio(recent)
print(lst[0])
