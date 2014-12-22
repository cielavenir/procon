#!/usr/bin/ruby
a=gets.to_i.times.map{gets.chomp}
p [*'a'..'z'].count{|e|a.all?{|f|f.include?(e)}}