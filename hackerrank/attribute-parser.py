#!/usr/bin/python
import sys,xml.etree.ElementTree
if sys.version_info[0]>=3: raw_input=input
n,m=[int(e) for e in raw_input().split()]
s='<root>'
for _ in range(n): s+=raw_input()
xml=xml.etree.ElementTree.fromstring(s+'</root>')
for _ in range(m):
	try:
		d,r=raw_input().strip().split('~')
		elems=xml.findall('./'+'/'.join(d.split('.')))
		if not elems:
			print('Not Found!')
		else:
			print(elems[0].get(r) or 'Not Found!')
	#split('~') failed
	except ValueError:
		print('Not Found!')