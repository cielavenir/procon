#!/usr/bin/python
#compat with both Py2/Py3
import sys
if sys.version_info[0]>=3: raw_input=input

def main(roman):
	m={'I':1,'V':5,'X':10,'L':50,'C':100,'D':500,'M':1000}
	r=0
	for i in range(len(roman)):
		r+=m[roman[i]]*(1 if i==len(roman)-1 or m[roman[i]]>=m[roman[i+1]] else -1)
	print(str(r))

if __name__=='__main__':
	try:
		while True:
			main(raw_input().rstrip())
	except EOFError:
		pass