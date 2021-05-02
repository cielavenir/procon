#!/usr/bin/ruby
s=gets.chomp.chars;%w(+ -).repeated_permutation(3){|_|a=s.zip(_)*'';(puts a+'=7';exit)if eval(a)==7}
