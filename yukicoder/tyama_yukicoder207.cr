#!/usr/bin/env crystal
a,b=gets.not_nil!.split.map &.to_i
puts (a..b).select{|i|i%3==0||i.to_s=~/3/}.join("\n")