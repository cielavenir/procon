#!/usr/bin/ruby
n=gets.to_i
s=gets.chomp
a=[0];b=[0]
n.times{|i|
a.push a[-1]+(s[i]==?W ? 1 : 0)
b.unshift b[0]+(s[n-i-1]==?E ? 1 : 0)
}
p (n+1).times.map{|i|a[i]+b[i]}.min
