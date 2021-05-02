#!/usr/bin/ruby
gets;puts$<.map.with_index{|e,i|e.split.map(&:to_i)+[i]}.group_by{|e|e[0]}.flat_map{|_,e|e.sort.map.with_index{|f,i|['%06d%06d'%[f[0],i+1],f[2]]}}.sort_by{|e|e[1]}.map &:first
