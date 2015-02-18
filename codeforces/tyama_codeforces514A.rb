#!/usr/bin/env ruby
a=gets.chomp.bytes.map{|e|[57-e,e-48].min}
a[0]=9 if a[0]==0
puts a*''