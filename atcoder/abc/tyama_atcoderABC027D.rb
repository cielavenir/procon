#!/usr/bin/ruby
x=0
y=0
a=[]
gets.chomp.chars{|c|
	if c=='+'
		x+=1
	elsif c=='-'
		y+=1
	else
		a<<y-x
	end
}
a.sort!
p a[a.size/2..-1].reduce(0,:+)-a[0,a.size/2].reduce(0,:+)