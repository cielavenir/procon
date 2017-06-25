#!/usr/bin/ruby
f=->a,b,c{a!=c&&((b<a&&b<c)||(b>a&&b>c))}
a=gets.split.map &:to_i
puts f[*a]?:INF:(1..1e3).count{|i|f[*a.map{|e|e%i}]}