#!/usr/bin/ruby
H,W,D=gets.split.map &:to_i
H.times{|h|puts W.times.map{|w|:RYGB[(h+w)/D*2+(h-w)/D&3]}*''}
