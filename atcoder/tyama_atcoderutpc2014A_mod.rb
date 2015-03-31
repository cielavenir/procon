#!/usr/bin/ruby
s=' '+gets.chomp+' '
1 while s.sub!(/ not not (?!(not( |$)))/,' ')
puts s.strip