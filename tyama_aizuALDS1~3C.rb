#!/usr/bin/ruby
a=[]
gets.to_i.times{
	s,n=gets.split
	if s=='insert'
		a.unshift(n.to_i)
	elsif s=='delete'
		a.length.times{|i|if a[i]==n.to_i then a.delete_at(i);break end}
	elsif s=='deleteFirst'
		a.shift
	else
		a.pop
	end
}
puts a*' '