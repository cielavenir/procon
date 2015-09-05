#!/usr/bin/ruby
n=gets.to_i
a=gets.split.map(&:to_f).sort
p (a[n/2]+a[~-n/2])/2