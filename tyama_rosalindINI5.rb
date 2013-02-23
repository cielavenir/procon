#!/usr/bin/ruby
ARGF.each_with_index{|e,i|puts e if i.odd?}