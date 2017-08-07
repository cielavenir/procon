#!/usr/bin/ruby
N,*A=`dd`.split.map &:to_i
h=Hash.new 0
A.each{|e|h[2.downto(0).find{|i|e%2**i==0}]+=1}
a=(0..2).find{|i|h[i]>0}
h[a]-=1
while h.values.any?{|e|e>0}
	st=2-a
	a=(st..2).find{|i|h[i]>0}
	if !a
		puts :No
		exit
	end
	h[a]-=1
end
puts :Yes
