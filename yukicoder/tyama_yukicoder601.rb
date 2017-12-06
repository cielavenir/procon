#!/usr/bin/ruby
gets;puts$<.group_by{|e|e.split.map{|f|f.to_i.odd?}}.map{|k,v|v.size/2}.reduce(:+).odd? ? :Alice : :Bob
