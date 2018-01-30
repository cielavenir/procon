#!/usr/bin/ruby
n,k=gets.split.map &:to_i
m=(6*k).times.map{[0]*(6*k)}
n.times{
	x,y,c=gets.split.zip([:to_i,:to_i,:to_s]).map{|x,y|y.to_proc[x]}
	y+=k if c==?W
	x%=2*k
	y%=2*k
	4.times{|i|
		(i%2).step(3,2){|j|
			m[x+i*k][y+j*k]+=1
			m[x+i*k+k][y+j*k]-=1
			m[x+i*k][y+j*k+k]-=1
			m[x+i*k+k][y+j*k+k]+=1
		}
	}
}
(0...6*k).each{|i|(1...6*k).each{|j|m[i][j]+=m[i][j-1]}}
(1...6*k).each{|i|(0...6*k).each{|j|m[i][j]+=m[i-1][j]}}
p m.map(&:max).max
