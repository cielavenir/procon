#!/usr/bin/ruby
def f(c,n)
	n==0 ? '' : n>0 ? c*n : c*-n
end
def g(n)
	n==0 ? '' : n>0 ? 'C'.upcase*(n-1) : 'W'.upcase*(-n-1)
end

x,y,z=gets.split.map &:to_i
if z==0
	puts :wwW
elsif y==0
	if x==0||z%x>0
		puts :NO
	else
		s='c'*(z/x)+'C'*(z/x-1)
		puts s.size>10000 ? :NO : s
	end
else
	if (-5000..5000).each{|a|
		b,r=(z-a*x).divmod(y)
		next if r>0||2*a.abs+2*b.abs-1>10000
		if a>0
			puts f('w',b)+f('c',a)+g(a)+g(b)+(a==0||b==0 ? '' : b<0 ? 'W' : 'C')
		else
			puts f('c',a)+f('w',b)+g(b)+g(a)+(a==0||b==0 ? '' : a<0 ? 'W' : 'C')
		end
		break
	}
		puts :NO
	end
end
