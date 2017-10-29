#!/usr/bin/ruby
n,*a=`dd`.split.map &:to_i
h=Hash.new 0
puts a.any?{|e|h[e]+=1;e>2}||h[1]%2<1||h[2]>1?:B: :A
