#!/usr/bin/ruby
gets.to_i.times{
	n=gets.to_i
	a=[]
	b=[]
	n.times{
		_=gets.split.map(&:to_i).map{|_|_==-1 ? Float::INFINITY : _}
		a<<_
		b<<_.dup
	}
	n.times{|k|n.times{|i|n.times{|j|
		a[i][j]=[a[i][j],a[i][k]+a[k][j]].min
	}}}
	puts n.times.all?{|i|n.times.all?{|j|a[i][j]==b[i][j] && (i!=j||a[i][j]==0)}} ? :YES : :NO
}