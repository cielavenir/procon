#!/usr/bin/python
import email.utils,re
for _ in range(int(raw_input())):
	a=email.utils.parseaddr(raw_input().strip())
	if a[1]:
		b=a[1].split('@')
		if len(b)>1:
			c=b[1].split('.')
			# example.co.jp broken
			if len(c)==2 and re.search(r'^[a-zA-Z][0-9a-zA-Z-_\.]*$',b[0]) and all(re.search(r'^[a-zA-Z]+$',e) for e in c) and len(c[-1])<4:
				print(email.utils.formataddr(a))