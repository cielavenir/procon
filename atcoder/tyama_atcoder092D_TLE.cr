#!/usr/bin/env crystal
N=gets.not_nil!.to_i
A=gets.not_nil!.split.map &.to_i
B=gets.not_nil!.split.map &.to_i
r=0
(0..28).each{|b|
	r0=0
	t=1<<b
	a=A.map{|e|e % (2*t)}.sort
	B.map{|e|e % (2*t)}.each{|e|
		i1=(0...N).bsearch{|i|1*t-a[i]<=e}||N
		i2=(0...N).bsearch{|i|2*t-a[i]<=e}||N
		i3=(0...N).bsearch{|i|3*t-a[i]<=e}||N
		i4=(0...N).bsearch{|i|4*t-a[i]<=e}||N
		r0+=i4-i3+i2-i1
	}
	r^=r0%2*t
}
p r
