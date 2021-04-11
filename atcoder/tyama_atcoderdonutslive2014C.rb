#!/usr/bin/ruby
gets;r=-999;s=0
gets.split.each{|e|s+=e.to_i;r<s&&r=s;s<0&&s=0}
p r
