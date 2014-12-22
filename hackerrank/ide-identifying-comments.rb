#!/usr/bin/ruby
puts $<.read.scan(/(\/\*(.*?)\*\/|\/\/(.*?)\n)/m).map(&:first)