#!/usr/bin/ruby
a=Dir.open('/bin')
puts a.reject{|e|e.start_with?('.')}.sort
a.close