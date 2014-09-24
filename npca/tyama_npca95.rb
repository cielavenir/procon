#!/usr/bin/ruby
puts $<.drop(1).map(&:to_i).sort.instance_eval{self[size/2]}