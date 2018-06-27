#!/usr/bin/ruby
n,k,*a=$<.read.split.map &:to_i
p a.all?{|e|e<=k}?n:a.index{|e|e>k}+(n-1-a.rindex{|e|e>k})
