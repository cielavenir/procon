#!/usr/bin/ruby
N,*A=`dd`.split.map &:to_i
a=*0;b=*0
A.each_slice(2){|x,y|a<<a[-1]+x;b<<b[-1]+y}
p b[N]-a[N]+2*(0..N).map{|i|a[i]-b[i]}.max
