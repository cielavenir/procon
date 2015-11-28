#!/usr/bin/ruby
puts gets.chomp.tr(';',',').split(',',-1).partition{|e|e=~/^-?([1-9][0-9]*|0)$/}.map{|e|e.empty? ? '-' : '"'+e*','+'"'}