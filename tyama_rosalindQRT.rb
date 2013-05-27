#!/usr/bin/ruby
s=gets.chomp.split
h={}
while gets
a=$_.size.times.select{|i|$_[i,1]=='0'}
b=$_.size.times.select{|i|$_[i,1]=='1'}
a.combination(2){|a0|b.combination(2){|b0|h[[a0,b0].sort]=1}}
end
puts h.keys.map{|a,b|"{%s, %s} {%s, %s}"%[s[a[0]],s[a[1]],s[b[0]],s[b[1]]]}