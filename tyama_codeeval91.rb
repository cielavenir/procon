#!/usr/bin/ruby
ARGF.each{|e|puts e.split.map(&:to_f).sort.map{|f|sprintf '%.3f',f}*' '}