#!/usr/bin/ruby
gets
s=gets.chomp;p s.scan(/^\<+/).join.size+s.reverse.scan(/^\>+/).join.size
#p gets.scan(/(^\<+|\>+$)/).join.size
