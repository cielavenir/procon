#!/usr/bin/ruby
l,h=gets.split.map(&:to_i)
a=20.times.map{[]}
h.times{
	line=gets.chomp
	line.chars.each_slice(l).each_with_index{|e,i|a[i]<<e*''}
}
x,y=2.times.map{
	gets.to_i.times.map{
		gets.chomp
	}.each_slice(h).map{|e|
		a.index(e)
	}.reverse.each_with_index.reduce(0){|s,(e,i)|
		s+e*20**i
	}
}
n={'+'=>x+y,'-'=>x-y,'*'=>x*y,'/'=>(x/y rescue 0)}[gets.chomp]
if n==0
	puts a[0]
else
	r=[]
	while n>0
		r=a[n%20]+r
		n/=20
	end
	puts r
end