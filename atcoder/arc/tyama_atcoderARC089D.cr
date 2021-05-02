#!/usr/bin/env crystal
n,k=gets.not_nil!.split.map &.to_i
m=(6*k).times.map{[0]*(6*k)}.to_a
n.times{
	a=gets.not_nil!.split
	x=a[0].to_i
	y=a[1].to_i
	c=a[2]
	y+=k if c=="W"
	x%=2*k
	y%=2*k
	4.times{|i|
		(i%2).step(to:3,by:2){|j|
			m[x+i*k][y+j*k]+=1
			m[x+i*k+k][y+j*k]-=1
			m[x+i*k][y+j*k+k]-=1
			m[x+i*k+k][y+j*k+k]+=1
		}
	}
}
(0...6*k).each{|i|(1...6*k).each{|j|m[i][j]+=m[i][j-1]}}
(1...6*k).each{|i|(0...6*k).each{|j|m[i][j]+=m[i-1][j]}}
p m.map(&.max).max
