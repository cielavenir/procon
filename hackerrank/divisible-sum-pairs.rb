#!/usr/bin/ruby
n,k,*a=`dd`.split.map(&:to_i)
p a.combination(2).count{|x,y|(x+y)%k==0}
