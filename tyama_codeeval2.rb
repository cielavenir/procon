#!/usr/bin/ruby
n=gets.to_i;puts$<.map(&:chomp).sort{|a,b|-(a.size<=>b.size)}[0,n]