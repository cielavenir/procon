#!/usr/bin/ruby
n,k=gets.split.map &:to_i
r=0
t=95
gets.chomp.bytes.sort.each{|b|
	if b-t>1
		t=b
		r+=b-96
		k-=1
		break if k==0
	end
}
p k>0 ? -1 : r
