#!/usr/bin/ruby
gets.to_i.times{
	d,x,t=gets.split.map(&:to_i)

	n,k=[d+x-1,d-1]
	k=[k,n-k].min # if k>n/2
	r=1
	if t>0 && k.times{|i|
		r=r*(n-i)/(i+1)
		break if r>t
	}
		puts :AC
	else
		puts :ZETUBOU
	end
}