#!/usr/bin/ruby
while(m,a,b=gets.split.map(&:to_i))[0]!=0
	p m.times.map{gets.to_i}.each_cons(2).with_index(1).map{|(x,y),i|[x-y,i]}.drop(a-1).take(b-a+1).max[1]
end