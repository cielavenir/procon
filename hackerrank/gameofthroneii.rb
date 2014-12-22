#!/usr/bin/ruby
def perm(n,k) k.times.reduce(1){|s,i|s*=n-i} end
h=Hash.new(0)
gets.chomp.each_char{|c|h[c]+=1}
s=1
a=h.map{|k,v|v/2}
l=a.reduce(:+)
a.each{|e|
	s=s*perm(l,e)/perm(e,e)
	l-=e
}
p s%1000000007