#!/usr/bin/ruby
gets.to_i.times{
n=gets.to_i
p (n+~gets.split.map(&:to_i).sum)%-~n
}
