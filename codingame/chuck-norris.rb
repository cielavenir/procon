#!/usr/bin/ruby
puts gets.chomp.bytes.map{|b|'%07b'%b}.join.chars.chunk{|e|e}.flat_map{|k,v|[['00','0'][k.to_i],'0'*v.size]}*' '