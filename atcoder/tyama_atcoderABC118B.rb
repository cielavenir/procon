#!/usr/bin/ruby
gets;p$<.map{|e|e.split[1..-1]}.reduce(:&).size
