#!/usr/bin/ruby
s,e,n=gets.split
n=n.to_i
puts n<2 ? s==e ? s : -1 : s+'a'*(n-2)+e
