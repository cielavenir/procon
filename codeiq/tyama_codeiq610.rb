#!/usr/bin/ruby
#coding:utf-8
DATA.each{|e|
	n,m=e.split.map(&:to_i)
	count=0
	pieces=[n]
	while !pieces.empty?
		#p pieces
		cut=pieces.pop(m)
		cut.each{|e|
			pieces<<e/2
			pieces<<e-e/2
		}
		pieces.select!{|e|e>1}
		pieces.sort!
		count+=1
	end
	puts "#{count}回"
}
=begin
n-1回の切断が必要
7=1+2+3+1
19=1+2+3*5+1
99=1+2+4+5*18+2
=end
__END__
8 3
20 3
100 5