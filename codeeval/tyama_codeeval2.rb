#!/usr/bin/ruby
n=gets.to_i;puts$<.to_a.sort_by{|e|-e.size}[0,n]