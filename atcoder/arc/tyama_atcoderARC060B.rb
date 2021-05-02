#!/usr/bin/ruby
puts gets.chomp.chars.group_by{|e|e}.all?{|k,v|v.size%2==0}?:Yes: :No