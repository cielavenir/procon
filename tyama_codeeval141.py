#!/usr/bin/python
#coding:utf-8
import math,time,re#,sys,codecs
from xml.etree.ElementTree import XMLParser
'''
if sys.version_info[0]>=3:
	raw_input=input
else:
	sys.stdout = codecs.getwriter('utf-8')(sys.stdout)
'''

line=''
query=[]
while True:
	line=raw_input()
	if line[0:5]=='<?xml': break
	a=line.split('; (')
	query.append((float(a[0]),[float(e)*math.pi/180 for e in a[1][:-1].split(', ')]))

class Parser:
	ids=[]
	names=[]
	confirmation=[]
	timestamp=[]
	coor=[]
	current_tag=[]

	def start(self,tag,attrs):
		try:
			tag=tag[tag.index('}')+1:]
		except ValueError:
			pass
		self.current_tag.append(tag)
		if tag=='Placemark':
			try:
				self.ids.append(int(attrs['id']))
			except KeyError:
				pass
	def end(self,tag):
		try:
			tag=tag[tag.index('}')+1:]
		except ValueError:
			pass
		t=self.current_tag.pop()
		if t!=tag: raise Exception('xml is malformed /'+t)
	def data(self,txt):
		if self.current_tag==['kml','Document','Folder','Placemark','name']:
			self.names.append(txt)
		elif self.current_tag==['kml','Document','Folder','Placemark','TimeStamp','when']:
			self.timestamp.append(time.mktime(time.strptime(txt,'%Y-%m-%d %H:%M:%S.%f')))
		elif self.current_tag==['kml','Document','Folder','Placemark','Point','coordinates']:
			self.coor.append([float(e)*math.pi/180 for e in txt.split(',')])
		elif self.current_tag==['kml','Document','Folder','Placemark','description']:
			x=re.search(r'Confirmation: <b>(\d+)</b> people',txt)
			if x: self.confirmation.append(int(x.group(1)))
	def close(self):
		return list(zip(self.confirmation,self.timestamp,self.ids,self.coor,self.names))

parser=XMLParser(target=Parser(),encoding='utf-8')
parser.feed(line)
try:
	while True:
		parser.feed(raw_input())
except EOFError:
	pass
a=sorted(parser.close(),key=lambda e:(-e[0],-e[1],e[2]))

for e0 in query:
	radius,coor1=e0
	result=[]
	num=None
	for e1 in a:
		confirmation,timestamp,id,coor2,name=e1
		if radius>=6378.137*math.acos( (math.sin(coor1[1])*math.sin(coor2[1])+math.cos(coor1[1])*math.cos(coor2[1])*math.cos(coor1[0]-coor2[0])) ):
			if num!=None and num>confirmation: break
			result.append(name)
			num=confirmation
	if len(result)==0:
		print('None')
	else:
		print(', '.join(result))