#!/usr/bin/ruby
gets;$<.map{|e|a,b,c,d=e.split.map &:to_i;g=b.gcd d;puts d<b||a<b||g-a%g<b-c ?:No: :Yes}
