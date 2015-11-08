#!/usr/bin/python
from __future__ import print_function
import sys
if sys.version_info[0]>=3: raw_input=input

class BF:
	buffer=[0]*99999
	ptr=0
	inpptr=0
	inst=0
	def __init__(self,s):
		self.inp=s
	def execute(self,s):
		i=0
		while i<len(s):
			if s[i]=='>': self.ptr+=1;self.inst+=1
			elif s[i]=='<': self.ptr-=1;self.inst+=1
			elif s[i]=='+': self.buffer[self.ptr]+=1;self.inst+=1
			elif s[i]=='-': self.buffer[self.ptr]-=1;self.inst+=1
			elif s[i]=='.':
				self.inst+=1
				if self.inst>100000:
					raise
				print(chr(self.buffer[self.ptr]),end='')
			elif s[i]==',':
				self.inst+=1
				if self.inst>100000:
					raise
				self.buffer[self.ptr]=ord(self.inp[self.inpptr]);self.inpptr+=1
			elif s[i]=='[':
				self.inst+=1
				if self.buffer[self.ptr]: self.execute(s[i+1:])
				marker=1
				while marker:
					if s[i+1]=='[': marker+=1
					if s[i+1]==']': marker-=1
					i+=1
			elif s[i]==']':
				self.inst+=1
				if self.buffer[self.ptr]:
					self.inst+=1
					i=-1
				else: return
			i+=1
			if self.inst>100000:
				raise

n,m=map(int,raw_input().split())
bf=BF(raw_input().rstrip()[:-1])
prog=''
for _ in range(m):prog+=raw_input()
try:
	bf.execute(prog)
except:
	print()
	print('PROCESS TIME OUT. KILLED!!!')