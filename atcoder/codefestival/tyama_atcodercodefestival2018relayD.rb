#!/usr/bin/ruby
N=gets.to_i
P=$<.map{|e|e.split.map &:to_i}
p (-1e9..1e9).bsearch{|m|P.max_by{|n,w|(n-m).abs*w}[0]<m}
