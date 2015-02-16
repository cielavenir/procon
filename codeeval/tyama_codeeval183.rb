#!/usr/bin/ruby
puts $<.map{|e|e.chomp.split(',').map{|f|f.match(/X(\.*)Y/)[1].size}.min}