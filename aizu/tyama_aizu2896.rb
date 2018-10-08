#!/usr/bin/ruby
a,b,*x=$<.read.split.map &:to_i;p x.count{|e|e>b}
