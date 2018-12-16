#!/usr/bin/ruby
gets;puts$<.map{|e|e=e.chomp.chars.sort*'';e[0]<e[-1] ? e : -1}
