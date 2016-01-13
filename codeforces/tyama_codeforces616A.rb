#!/usr/bin/ruby
a,b=$<.map{|e|e.chomp.sub(/^0+/,'')}
puts '=><'[(a.size<=>b.size)!=0 ? a.size<=>b.size : a<=>b]