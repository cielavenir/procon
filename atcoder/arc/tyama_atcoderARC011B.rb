#!/usr/bin/ruby
gets;puts gets.chomp.downcase.tr('aeiouy,.','').split.map{|e|e.chars.map{|f|'zrbcdwtjfqlvsxpmhkng'.index(f)/2}*''}*' '