#!/usr/bin/ruby
p gets.chomp.chars.zip('CODEFESTIVAL2016'.chars).count{|x,y|x!=y}
