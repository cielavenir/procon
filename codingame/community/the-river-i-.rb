#!/usr/bin/ruby
x=Enumerator.new{|y|
	n=gets.to_i
	y<<n
	loop{
		n+=n.to_s.chars.map(&:to_i).reduce :+
		y<<n
	}
}
m=x.next
n=gets.to_i
loop{
	m=x.next while m<n
	(p m;exit) if m==n
	n+=n.to_s.chars.map(&:to_i).reduce :+ while m>n
}
