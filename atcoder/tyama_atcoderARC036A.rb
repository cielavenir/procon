#!/usr/bin/ruby
n,k=gets.split.map(&:to_i)
p ($<.map(&:to_i).each_cons(3).with_index(3).find{|a,i|a.reduce(:+)<k}||[[],-1])[1]