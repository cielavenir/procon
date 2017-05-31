#!/usr/bin/ruby
#based on @hanada3355's solution
n=gets.to_i
*b=a=n.step(n*n,n).to_a
gets.split.map.with_index{|e,i|a[e.to_i-1]+=i}
p *a,*b.reverse
#puts a*' ',b.reverse*' '
