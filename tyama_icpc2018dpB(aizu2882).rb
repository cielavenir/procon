#!/usr/bin/ruby
loop{
	n,l,r=gets.split.map &:to_i
	break if n<1
	a=n.times.map{gets.to_i}+[1]
	p (l..r).count{|i|
		a.size.times.find{|j|i%a[j]==0}%2==0
	}
}
