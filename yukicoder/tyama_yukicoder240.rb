#!/usr/bin/ruby
h={[0,0]=>1}
A=[[-2,-1],[-2,1],[-1,-2],[-1,2],[2,-1],[2,1],[1,-2],[1,2]]
(1..3).each{|n|
	A.repeated_combination(n){|a|h[a.transpose.map{|e|e.reduce(:+).abs}]=1}
}
B=h.keys.sort.select{|x,y|x<=y}.map(&:join)
#p B
#p B.include?(gets.split.map{|e|e.to_i.abs}.minmax*'')?:YES: :NO

puts'0011233450240360405131416'.index(gets.split.map{|e|n=e.to_i.abs;n>9?-1:n}.sort*'')?:YES: :NO
puts'0011233450240360405131416'.index(S=gets.tr("- \n","").chars.sort*'')&&S.size<3?:YES: :NO