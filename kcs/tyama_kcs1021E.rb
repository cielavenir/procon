#!/usr/bin/ruby
n,m=gets.split.map(&:to_i)
puts $<.map(&:to_i).reduce([0,1]){|(s,t),e|[(s+e)%m,(t*e)%m]}*' '