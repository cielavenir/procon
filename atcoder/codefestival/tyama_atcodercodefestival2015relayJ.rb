#!/usr/bin/ruby
def f(e)
	x,y=e.minmax
	return (y%2)^1 if x==1
	return 1 if x==3&&y==4
	return 0 if (x==4&&y==4) || (x==2&&y%4==2) || (x==3&&y%4==0)
	1
end
puts [:rng,:snuke][f(gets.split.map(&:to_i))]