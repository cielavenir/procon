#!/usr/bin/ruby
n,*a=$<.read.split.map &:to_i;p n-a.group_by{|e|e}.map{|k,v|v.size}.max