#!/usr/bin/ruby
puts ARGF.lines.map{|e|e.chomp.split''}.transpose.map{|l|l.instance_eval{map{|e,i|e==first ? 1:0}}.join}.select{|e|1<e.scan(/0/).size&&1<e.scan(/1/).size}*"\n"