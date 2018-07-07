#!/usr/bin/python
import sys,functools
if sys.version_info[0]>=3:
	maketrans=str.maketrans
else:
	from string import maketrans

O=lambda a:lambda b:a|b
A=lambda a:lambda b:a&b
X=lambda a:lambda b:a^b
while True:
	s=sys.stdin.readline().rstrip().translate(maketrans('+*^[]','OAX()'))
	if s=='.': break
	for c in 'abcd': s=s.replace(c,'(%s)'%c)
	s=s[1:-1]
	n=int(sys.stdin.readline())
	r=eval(s.translate(maketrans('abcd','%04d'%n)))
	print('%d %d'%(r,sum(r==eval(s.translate(maketrans('abcd','%04d'%i))) for i in range(10000))))
