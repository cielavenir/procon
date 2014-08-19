#!/usr/bin/ruby
puts$<.each{|e|e.split.map(&:to_f).sort.map{|f|'%.3f'%f}*' '}