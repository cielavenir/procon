#!/usr/bin/ruby
n,*a=`dd`.split.map &:to_i
f=->i{(1..n).map{|e|puts [i,e]*' '}}
p 2*n-1
x,y=a.minmax
if y.abs>x.abs
f[a.index(y)+1]
(1...n).each{|e|puts [e,e+1]*' '}
else
f[a.index(x)+1]
n.downto(2){|e|puts [e,e-1]*' '}
end
