#!/usr/bin/ruby
N=gets.to_i
A=gets.split.map(&:to_i)
S=A.reduce(:+)
r=-Float::INFINITY
(0...N).each{|i|
	a=(0...N).map{|j|
		if i==j
			[-Float::INFINITY]
		else
			score=[0,0]
			side=0
			(0...N).each{|k|
				next unless i<=k&&k<=j || j<=k&&k<=i
				score[side]+=A[k]
				side^=1
			}
			[score[1],-j,score[0]]
		end
	}.max
	r=[r,a[2]].max
}
p r