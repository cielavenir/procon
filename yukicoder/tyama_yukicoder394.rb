#!/usr/bin/ruby
n=gets.split.map(&:to_i).sort[1..-2].reduce(:+)*25;puts '%d.%02d'%[n/100,n%100]