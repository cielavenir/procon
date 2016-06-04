#!/usr/bin/python
checkio=lambda data: ['','M','MM','MMM','MMMM'][data//1000]+['','C','CC','CCC','CD','D','DC','DCC','DCCC','CM'][data//100%10]+['','X','XX','XXX','XL','L','LX','LXX','LXXX','XC'][data//10%10]+['','I','II','III','IV','V','VI','VII','VIII','IX'][data%10]

def convert(roman):
	m={'I':1,'V':5,'X':10,'L':50,'C':100,'D':500,'M':1000}
	r=0
	for i in range(len(roman)):
		r+=m[roman[i]]*(1 if i==len(roman)-1 or m[roman[i]]>=m[roman[i+1]] else -1)
	return r

import sys
if sys.version_info[0]>=3: raw_input=input
print(checkio(convert(raw_input().strip())+convert(raw_input().strip())))