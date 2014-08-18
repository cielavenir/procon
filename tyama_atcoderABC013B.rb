#!/usr/bin/ruby
a,b=$<.map(&:to_i)
p [(a-b)%10,(b-a)%10].min