#!/usr/bin/ruby
n,k=gets.split.map(&:to_i)
p (1..9).find{|i|n*i%10==k||n*i%10==0}
