#!/usr/bin/ruby
gets
$<.map{|e|l,r,d=e.split.map &:to_i;p d+(d<l ? 0 : r/d*d)}
