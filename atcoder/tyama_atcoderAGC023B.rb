#!/usr/bin/ruby
n=gets.to_i
m=$<.map{|e|e.chop.chars}
p n*(0...n).count{m.rotate! ==m.transpose}
