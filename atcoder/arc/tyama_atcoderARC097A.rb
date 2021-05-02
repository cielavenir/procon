#!/usr/bin/ruby
a,b,c,d=gets.split.map &:to_i;puts (a-c).abs<=d||((a-b).abs<=d&&(b-c).abs<=d)?:Yes: :No
