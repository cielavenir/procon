#!/usr/bin/python
from __future__ import print_function
import sys
if sys.version_info[0]>=3:
	raw_input=input
	from html.parser import HTMLParser
else:
	from HTMLParser import HTMLParser

from HTMLParser import HTMLParser
class MyHTMLParser(HTMLParser):
	def handle_starttag(self, tag, attrs):
		print(tag)
		for e in attrs: print("-> "+e[0]+" > "+str(e[1]))
	def handle_endtag(self, tag):
		#print("End   : "+tag)
		pass
	def handle_startendtag(self, tag, attrs):
		print(tag)
		for e in attrs: print("-> "+e[0]+" > "+str(e[1]))

parser = MyHTMLParser()
for _ in range(int(raw_input())):
	parser.feed(raw_input())