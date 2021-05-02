#!/usr/bin/ruby
H,W=gets.split.map &:to_i
h=Hash.new 0
$<.read.chars{|c|c!="\n"&&h[c]+=1}
g=0;puts h.values.count{|e|g+=e%4>1?1:0;e%2>0}>1||g>W%2*H/2+H%2*W/2 ? :No : :Yes
