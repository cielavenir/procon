#!/usr/bin/ruby
n,m,*a=$<.read.split.map &:to_i;puts a.chunk(&:odd?).select{|k,v|k&&v.size>=m}.map{|k,v|v.sum}
