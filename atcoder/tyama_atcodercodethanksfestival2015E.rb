#!/usr/bin/ruby
gets
puts$<.map{|e|a,b=e.split;a.tr(?^+b,'').include?(b) ? :YES : :NO}