#!/usr/bin/ruby
gets
p gets.scan(/x{3,}/).map{|e|e.size-2}.reduce(0,:+)
