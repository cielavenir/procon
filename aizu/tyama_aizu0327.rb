#!/usr/bin/ruby
Q='?+??+???==???'
q0=Q.size.times.select{|i|Q[i]=='?'}
a=gets.split.map(&:to_i)
a.each_with_index{|e,i|Q[q0[i]]=e.to_s if e!=-1}
q1=Q.size.times.select{|i|Q[i]=='?'}
p ([*1..9]-a).permutation.count{|a|
	s=Q.dup
	a.each_with_index{|e,i|s[q1[i]]=e.to_s}
	eval s
}
