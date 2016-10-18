#!/usr/bin/ruby
s=gets.chomp
puts s.count(?0)>2||s=~/1$/ ? :SURVIVED : :DEAD
