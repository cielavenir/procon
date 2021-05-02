#!/usr/bin/ruby
x,y=gets.split.map &:to_i
puts gets.chomp=~/^\d{#{x}}-\d{#{y}}$/?:Yes: :No
