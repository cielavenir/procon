#!/usr/bin/env crystal
a=ARGF.gets_to_end.split.map &.to_i64;n,x=a.shift 2;b=a.dup;p (0...n).map{|i|t=x*i;n.times{|j|t+=b[j]=[b[j],a[(j-i)%n]].min};t}.min