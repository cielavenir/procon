#!/usr/bin/ruby
n=gets.to_i
a=gets.split.map &:to_i
gets.to_i.times{k=gets.to_i;puts [(0...n).bsearch{|i|a[i]>=k}||n,(0...n).bsearch{|i|a[i]>k}||n]*' '}
