#!/usr/bin/ruby
def c(y)
	if y%400==0
		366
	elsif y%100==0
		365
	elsif y%4==0
		366
	else
		365
	end
end
def d(q, y)
	if q<334
		q
	else
		q + c(y-12) - c(y+1)
	end
end
Y,N,D=gets.split.map &:to_i
puts [N-[N,d(D,Y)].min, [N, c(Y-12)-d(D,Y)].min]*' '
