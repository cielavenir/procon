#!/usr/bin/ruby
puts$<.map{|e|e.chomp.chars}.transpose.all?{|e|e.index(?o)}?:Yes: :No