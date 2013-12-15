#!/usr/bin/python
#python codeiq313.py <personal_names.xml >personal_names.txt
#May 20: Python3 compat
from __future__ import print_function
import sys,io,codecs
from xml.etree.ElementTree import XMLParser
if sys.version_info[0]<3: sys.stdout = codecs.getwriter('utf-8')(sys.stdout)
class Parser:
	line=0
	row=0
	in_td=False
	def start(self, tag, attrib):
		if tag=='tr':
			self.row=0
		if tag=='td':
			self.row+=1
			self.in_td=True
	def end(self, tag):
		if tag=='tr':
			print()
		if tag=='td':
			self.in_td=False
	def data(self,data):
		if self.in_td:
			if self.row==1:
				print("%s," % data.strip(),end='')
			if self.row==2:
				print("%s," % ','.join(data.strip().split()),end='')
			if self.row==3:
				print("%s" % data.strip(),end='')
	def close(self):
		pass

reader = io.open(sys.stdin.fileno(),'rb',0)
xml=reader.readall()
reader.close()
parser=XMLParser(target=Parser())
parser.feed(xml)
parser.close()