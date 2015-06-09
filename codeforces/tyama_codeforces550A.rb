#!/usr/bin/env ruby
s=gets.chomp
puts ((x=s.index('AB'))&&(y=s.rindex('BA'))&&y-x>1) || ((x=s.index('BA'))&&(y=s.rindex('AB'))&&y-x>1) ? :YES : :NO