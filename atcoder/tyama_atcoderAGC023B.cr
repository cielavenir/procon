#!/usr/bin/env crystal
n=gets.not_nil!.to_i
m=ARGF.gets_to_end.split.map{|e|e.chomp.chars}
p n*(0...n).count{|i|t=m.rotate(i);t==t.transpose}
