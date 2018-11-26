#!/usr/bin/ruby
gets;puts$<.map{|e|e.split[1..-1]}.reduce(:&)*' '
