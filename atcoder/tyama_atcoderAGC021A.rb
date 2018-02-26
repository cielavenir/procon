#!/usr/bin/ruby
s=gets.chomp
p s[0].to_i+9*~-s.size-(s=~/^.9*$/?0:1)
