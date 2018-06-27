#!/usr/bin/ruby
puts gets.codepoints.each_cons(3).any?{|x,y,z|x^y^z==64}?:Yes: :No
