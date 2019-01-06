#!/usr/bin/env crystal
a=ARGF.gets_to_end.split.map &.to_i
n,k=a.shift(2) #k=2 for A
b=[0]
(1...n).each{|i|
	b<<(1..k).map{|j|j>i ? 1<<29 : b[i-j]+(a[i]-a[i-j]).abs}.min}
p b[n-1]
