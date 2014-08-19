#!/usr/bin/ruby
gets;p gets.chomp.chars.group_by{|e|e}.count{|k,v|v.size&1==1}