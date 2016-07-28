#!/usr/bin/ruby
gets.to_i.times{
	a,b=gets.split('/').map(&:to_i)
	if b==0
		puts 'DIVISION BY ZERO'
	elsif a==0
		p 0
	else
		if b<0
			a=-a
			b=-b
		end
		if a<0
			print '-'
			a=-a
		end
		if a>=b
			print a/b
			a%=b
			print ' ' if a>0
		end
		if a>0
			g=a.gcd(b)
			print '%d/%d'%[a/g,b/g]
		end
		puts
	end
}