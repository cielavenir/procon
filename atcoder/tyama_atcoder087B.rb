#!/usr/bin/ruby
puts (gets.chomp.chars.sort<=>gets.chomp.chars.sort.reverse)<0 ? :Yes : :No
