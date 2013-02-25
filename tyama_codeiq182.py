#!/usr/bin/python
#first version: Jan 25
import sys
import random

if len(sys.argv)<7:
	print "give me 5 numbers and count"
	sys.exit()
mynum=[int(x) for x in sys.argv[1:6]]
mycnt=int(sys.argv[6])

carryover=0 #fixme
sellnum=random.randint(200000,300000)+mycnt #fixed in Jan 27
print "uriage=%d"%(sellnum*500)
print "toribun=%d"%(sellnum*200)
total=sellnum*300+carryover
paidmoney=[total/2,total/3,total/6]
carryover=total-sum(paidmoney)
sell=[random.sample(range(1,41),5) for x in range(sellnum)]
atari=sorted(random.sample(range(1,41),5))
a=[0,0,0,0,0,0]
for x in sell: a[len(set(x)&set(atari))]+=1
mymatch=len(set(mynum)&set(atari))
a[mymatch]+=mycnt

print "atari="+(','.join([str(x) for x in atari]))
for x in range(3):
	if a[5-x]==0:
		print "prize %d=0"%(x+1)
		carryover+=paidmoney[x]
	else:
		print "prize %d=%d(%d)"%(x+1,a[5-x],paidmoney[x]/a[5-x])
		#to consider: does hasuu need to carryover?
		carryover+=paidmoney[x]-paidmoney[x]/a[5-x]*a[5-x]
print "carryover=%d"%(carryover)
if mymatch<3:
	print "my loto didn't win"
else:
	print "my loto won prize %d(%d)"%(6-mymatch,paidmoney[5-mymatch]*mycnt)