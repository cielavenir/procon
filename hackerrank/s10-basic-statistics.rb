#!/usr/bin/ruby
n=gets.to_i
a=gets.split.map(&:to_i).sort
p a.reduce(:+).to_f/n
p n%2>0 ? a[n/2] : (a[n/2-1]+a[n/2])/2.0
p a.group_by{|e|e}.max_by{|k,v|[v.size,-k]}[0]
