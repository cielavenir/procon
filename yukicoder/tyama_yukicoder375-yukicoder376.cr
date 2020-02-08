#!/usr/bin/env crystal
m=n=gets.not_nil!.to_i64
y=(1_i64..n**0.5).reject{|i|n%i>0}
y.map{|a|y.each{|b|c=a*b;n%c==0&&(m=[m,a+b+n//c-3].min)}}
print m," ",n-1
