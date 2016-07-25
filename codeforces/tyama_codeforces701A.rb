#!/usr/bin/ruby
n=gets.to_i
a=gets.split.map(&:to_i).each.with_index(1).sort
(n/2).times{puts [a.shift[1],a.pop[1]]*' '}