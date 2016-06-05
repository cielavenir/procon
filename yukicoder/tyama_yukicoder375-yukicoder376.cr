#!/usr/bin/ruby
m=n=gets.not_nil!.to_i64
y=(1_i64..Math.sqrt(n)).reject{|i|n%i>0}
y.map{|a|y.each{|b|m=[m,a+b+n/a/b-3].min if n% (a*b)==0}}
print m," ",n-1