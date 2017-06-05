#!/usr/bin/ruby
#https://qiitadon.com/@nabetani/24659

while gets
	n=$_.to_i
	a,b=0,1
	loop{
		a,b=b,a+b
		if a==n
			p b
			break
		elsif a>n
			puts :-
			break
		end
	}
end
