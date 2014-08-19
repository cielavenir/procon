#!/usr/bin/ruby
n=gets.to_i
if n<4
	p -1
elsif n==4
	puts "....\n.##.\n.##.\n...."
else
	a=n.times.map{'.'*n}
	if n%2==1
		a[1][1,1]='#'
		n-=1
	end
	(n/2).times{|i|
		a[2+i-1][2+i,1]=a[2+i][2+i-1,1]='#'
	}
	puts a
end