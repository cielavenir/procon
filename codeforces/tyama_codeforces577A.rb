#!/usr/bin/ruby
n,x=gets.split.map(&:to_i)
p 1.step(n).count{|i|x%i==0&&x/i<=n}