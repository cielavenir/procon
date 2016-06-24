#!/usr/bin/ruby
n,x=gets.split.map(&:to_i)
r=0
n.times{
	a,b=gets.split.zip([:to_s,:to_i]).map{|x,y|x.send(y)}
	if a=='-'
		if b>x
			r+=1
		else
			x-=b
		end
	else
		x+=b
	end
}
puts [x,r]*' '