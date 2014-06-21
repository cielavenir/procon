#!/usr/bin/python
from xml.etree.ElementTree import XMLParser
import sys
if sys.version_info[0]>=3: raw_input=input

class Parser:
	score=0
	def start(self, tag, attrib):
		self.score+=len(attrib)
	def end(self, tag):
		pass
	def data(self,data):
		pass
	def close(self):
		return self.score

parser=XMLParser(target=Parser())
for i in range(int(raw_input())):
	parser.feed(raw_input())
print(parser.close())