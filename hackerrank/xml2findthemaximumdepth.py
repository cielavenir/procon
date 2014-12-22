#!/usr/bin/python
from xml.etree.ElementTree import XMLParser
import sys
if sys.version_info[0]>=3: raw_input=input

class Parser:
	max_depth=0
	depth=-1
	def start(self, tag, attrib):
		self.depth+=1
		self.max_depth=max(self.depth,self.max_depth)
	def end(self, tag):
		self.depth-=1
	def data(self,data):
		pass
	def close(self):
		return self.max_depth

parser=XMLParser(target=Parser())
for i in range(int(raw_input())):
	parser.feed(raw_input())
print(parser.close())