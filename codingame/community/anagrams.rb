#!/usr/bin/ruby
def scramble(s,n,&blk)
	x=[]
	s.bytes{|b|x<<b if b>64&&(b-64)%n==0}
	y=blk[x]
	s.bytes.map{|b|
		if x.first==b
			b=y.shift
			x.shift
		end
		b.chr
	}*''
end
a=gets.split
w=a.map(&:size).reverse
s=a.join.chars
a=[]
w.each{|e|a<<s.shift(e).join}
s=a*' '
s=scramble(s,4){|a|a.rotate(-1)}
s=scramble(s,3){|a|a.rotate(1)}
s=scramble(s,2){|a|a.reverse}
puts s