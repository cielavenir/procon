#!/usr/bin/ruby
n=gets.to_i
p n/(2..n).find{|e|n%e==0}