#!/usr/bin/ruby
a,b,c=gets.split
c=c[3..-1]
c=(c.index('.') ? c.tr('.','') : c+'0').to_i*6
n=(a.to_i*60+b.to_i+c-540)%1440
puts '%02d:%02d'%[n/60,n%60]
