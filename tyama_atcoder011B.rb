#!/usr/bin/ruby
t='zrbcdwtjfqlvsxpmhkng'
gets;a=gets.chomp.downcase.tr('aeiouy,.','').split
puts a.map{|e|e.chars.map{|f|t.index(f)/2}.join}.join(' ')