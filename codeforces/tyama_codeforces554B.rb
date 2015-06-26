#!/usr/bin/ruby
p$<.drop(1).group_by{|e|e}.map{|k,v|v.size}.max