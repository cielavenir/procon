#!/usr/bin/python
import sys
class BF:
	buffer=[0]*9999
	ptr=0
	def execute(self,s):
		i=0
		while i<len(s):
			if s[i]=='>': self.ptr+=1
			elif s[i]=='<': self.ptr-=1
			elif s[i]=='+': self.buffer[self.ptr]+=1
			elif s[i]=='-': self.buffer[self.ptr]-=1
			elif s[i]=='.': sys.stdout.write(chr(self.buffer[self.ptr]))
			elif s[i]==',': self.buffer[self.ptr]=ord(sys.stdin.read(1))
			elif s[i]=='[':
				if self.buffer[self.ptr]: self.execute(s[i+1:])
				marker=1
				while marker:
					if s[i+1]=='[': marker+=1
					if s[i+1]==']': marker-=1
					i+=1
			elif s[i]==']':
				if self.buffer[self.ptr]: i=-1
				else: return
			i+=1

if __name__=='__main__':
	BF().execute('>+<,-------------------------------------------------[++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++.+++++.+++++++.----.++++++++++.-----------------.---.++++++++.-----------------------------------------------------------------------------------------------.---------->-<]>[++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++.+.+.---------------------------------------------------------.----------]')