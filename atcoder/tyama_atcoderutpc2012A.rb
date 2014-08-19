#!/usr/bin/ruby
a,*b=gets.chomp.split('/')
puts a.split('').sort==b.join.split('').sort ? 'yes':'no'