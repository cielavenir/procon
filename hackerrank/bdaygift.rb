#!/usr/bin/ruby
puts '%.1f'%[$<.drop(1).reduce(0){|s,e|s+=e.to_i}/2.0]