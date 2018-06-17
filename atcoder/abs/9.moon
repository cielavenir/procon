#!/usr/bin/env moon
t = [e\reverse() for e in *{"dream","dreamer","erase","eraser"}]
s = io.read("*l")\reverse()
c = 1
l = s\len()
while c<=l
	k = nil
	for e in *t
		if s\sub(c,c+e\len()-1)==e
			k = e
			break
	if k==nil
		print "NO"
		return
	c+=k\len()
print "YES"
