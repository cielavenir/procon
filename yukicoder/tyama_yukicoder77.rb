#!/usr/bin/ruby
def pyramid(n)
	a=[*1..n-1]
	a+[n]+a.reverse
end
N=gets.to_i
a=gets.split.map(&:to_i)
r=999999999
(1..1/0.0).each{|_i|
	py=pyramid(_i)
	diff=0
	abs=0
	[py.size,a.size].max.times{|i|
		x=(py[i]||0)-(a[i]||0)
		diff+=x
		abs+=x.abs
	}
	break if diff>0
	r=[r,abs/2-diff/2].min
}
p r