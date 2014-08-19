#!/usr/bin/ruby
a=Array(1024)
1024.times{|i| a[i]=i.to_s(2).to_i}
n=gets.to_i
1024.times{|i| if a[i+1]>n then puts i;exit end}