#!/usr/bin/ruby
x,y,n,*a=`dd`.split.map &:to_i
puts (n-1).times.all?{|i|x*a[i+1]>=y*a[i]}?:YES: :NO
