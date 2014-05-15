#!/usr/bin/ruby
gets.to_i.times{|i|a=gets.split.map(&:to_i);puts "Case ##{i+1}: O"+((a[1]+1)%2**a[0]==0?"N":"FF")}