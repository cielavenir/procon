#!/usr/bin/ruby
$<.each{|e|puts e.split.map(&:to_f).sort.map{|f|sprintf '%.3f',f}*' '}