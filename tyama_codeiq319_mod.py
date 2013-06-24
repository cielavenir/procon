#!/usr/bin/python
#May 20: Python3 compat
import sys
import random
appetizer=[]
maindish=[]
dessert=[]
for line in sys.stdin:
	#pseudo AI
	if any(line.find(e)>=0 for e in ['Frittata','Mussel','Soup','Chowder']):
		appetizer+=[line.rstrip()]
	elif any(line.find(e)>=0 for e in ['Vol-au-Vent','Pudding','Chocolate']):
		dessert+=[line.rstrip()]
	else:
		maindish+=[line.rstrip()]
while True:
	b=[random.choice(appetizer)]+[random.choice(maindish)]+[random.choice(dessert)]
	f=False
	for e in b:
		try:
			e.index('Chicken') #Does the menu include Chicken?
			f=True
		except ValueError:
			pass
	if f:
		for e in b: print(e)
		break