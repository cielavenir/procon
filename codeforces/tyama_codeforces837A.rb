#!/usr/bin/ruby
gets;p gets.split.map{|e|e.chars.count{|f|f==f.upcase}}.max
