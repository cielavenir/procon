#!/usr/bin/ruby
gets.chomp.to_i.times{|i|a=gets.chomp.split(" ").map!{|j|j=j.to_i};puts "Case ##{i+1}: O"+((a[1]+1)%2**a[0]==0?"N":"FF")}