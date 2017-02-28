#!/usr/bin/ruby
def convert(n)
	n.to_s(2).bytes.map{|b|b==48 ? 4 : 3}.reduce(:+)
end
s,n=gets.split.map(&:to_i)
n.times{
	s0=convert(s)
	break if s0==s
	s=s0
}
p s
