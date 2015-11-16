#!/usr/bin/ruby
puts $<.map{|e|e.chomp.chars}.transpose.all?{|e|e.any?{|f|f=='o'}} ? :Yes : :No