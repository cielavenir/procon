#!/usr/bin/ruby
s=gets.chomp
puts ((s.count('N')>0)^(s.count('S')>0)) || ((s.count('E')>0)^(s.count('W')>0)) ? :No : :Yes