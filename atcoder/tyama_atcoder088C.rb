#!/usr/bin/ruby
x,y=gets.split.map &:to_i;p (y/x).bit_length
