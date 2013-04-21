#!/usr/bin/ruby
n=gets.to_i;puts$<.map(&:chomp).sort{|a,b|-(a.length<=>b.length)}[0,n]