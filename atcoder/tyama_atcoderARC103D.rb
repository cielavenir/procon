#!/usr/bin/ruby
n=gets.to_i
x,y=$<.map{|e|e.split.map &:to_i}.transpose
q=(x[0].abs+y[0].abs)%2
(1...n).each{|i|
	if (x[i].abs+y[i].abs)%2!=q
		p -1
		exit
	end
}
m=31+(q^1)
p m
puts m.times.map{|i|i==31?1:2**i}*' '
x=x.map{|e|e-1} if p==0
n.times{|i|
	u=x[i]+y[i]
	v=x[i]-y[i]
	puts 31.times.map{|j|'LDUR'[((u - 1) / 2 + (1 << 30))[j]*2+((v - 1) / 2 + (1 << 30))[j]]}.join+(q==0 ? 'R' : '')
}
