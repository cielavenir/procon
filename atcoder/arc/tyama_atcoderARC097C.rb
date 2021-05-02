#!/usr/bin/ruby
s=gets.chomp;a=[];(0...s.size).map{|i|(1..5).map{|j|a<<s[i,j]}};puts a.uniq.sort[gets.to_i-1]
