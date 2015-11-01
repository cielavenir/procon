#!/usr/bin/ruby
data=gets.to_i.times.map{|i|
	n,m=gets.split.map(&:to_i)
	[Rational(n,m),i]
}.sort
result=[]
cnt=0
x=t=0
(1..1/0.0).each{|i|
	a=i.to_s.chars
	b=a.sort
	t+=1
	if a!=b && a!=b.reverse
		x+=1
		while cnt<data.size && Rational(x,t)>=data[cnt][0]
			result<<[i,data[cnt][1]]
			cnt+=1
		end
		break if cnt==data.size
	end
}
result.sort_by(&:last).each{|e|p e[0]}