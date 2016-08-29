#!/usr/bin/ruby
def f(n)
	if n==1
		return X
	elsif n==2
		return X+[X,Y].min
	elsif n%2==0
		return f(n/2)+[Y,X*(n-n/2)].min
	else
		return X+[f(n+1),f(n-1)].min
	end
end
N,X,Y=gets.split.map(&:to_i)
p f(N)