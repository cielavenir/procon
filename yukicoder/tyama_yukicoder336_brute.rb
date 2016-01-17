#!/usr/bin/ruby
n=gets.to_i
p [*1..n].permutation.count{|e|
	e.each_cons(3).all?{|x,y,z|x!=z&&((x<y&&z<y)||(x>y&&z>y))}
}