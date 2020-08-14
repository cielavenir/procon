#!/usr/bin/env crystal
lib C;fun strtoll(s: UInt8*,p: UInt8**,b: Int32): Int64;end
m=n=C.strtoll(gets.not_nil!,nil,10)
y=(1_i64..n**0.5).reject{|i|n%i>0}
y.map{|a|y.each{|b|c=a*b;n%c==0&&(m=[m,a+b+n//c-3].min)}}
print m," ",n-1
