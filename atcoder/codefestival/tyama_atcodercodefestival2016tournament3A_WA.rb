#!/usr/bin/ruby
N,M,K,*A=`dd`.split.map(&:to_i)
B=A.each_with_index.sort_by{|e,i|
	[-e,i]
}[0,K].sort_by{|e,i|
	i
}.map(&:first)
#p B
p (1..K).reduce(0){|s,i|s+i*B[i-1]}
