#!/usr/bin/ruby
s=0
gets.to_i.times{s+=gets.split.map(&:to_i).reduce(:*)}
p (s*1.05).to_i