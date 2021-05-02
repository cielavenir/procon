#!/usr/bin/ruby
a,b=$<.map{|e|e.chomp.chars}
puts a.zip(b)*''
