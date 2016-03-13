#!/usr/bin/ruby
p gets.split.map{|e|e.tr('.','').to_i}.reduce(:*)/10000