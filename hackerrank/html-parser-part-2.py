#!/usr/bin/python
from __future__ import print_function
import sys
if sys.version_info[0]>=3:
	raw_input=input
	from html.parser import HTMLParser
else:
	from HTMLParser import HTMLParser

class MyHTMLParser(HTMLParser):
	def handle_starttag(self, tag, attrs):
		#print("Start : "+tag)
		#for e in attrs: print("-> "+e[0]+" > "+str(e[1]))
		pass
	def handle_endtag(self, tag):
		#print("End   : "+tag)
		pass
	def handle_startendtag(self, tag, attrs):
		#print("Empty : "+tag)
		#for e in attrs: print("-> "+e[0]+" > "+str(e[1]))
		pass
	def handle_comment(self, data):
		#something is completely broken here
		print(">>> Multi-line Comment" if "\r" in data else ">>> Single-line Comment")
		print(data.replace("\r","\n"))
	def handle_data(self, data):
		if data.strip():
			print(">>> Data")
			print(data)

parser = MyHTMLParser()
html=''
for _ in range(int(raw_input())):
	html+=raw_input()
parser.feed(html)
parser.close()