#!/usr/bin/ruby
gets;p$<.map{|e|e.split('')}.transpose.map{|e|e.join.gsub(/o+/,?o).tr('^ox','').size}.reduce(:+)