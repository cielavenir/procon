#!/usr/bin/ruby
puts $<.read.scan(/(\/\*(.*?)\*\/|\/\/(.*?)\n)/m).map{|e|e.first.gsub(/^ +/m,'')}