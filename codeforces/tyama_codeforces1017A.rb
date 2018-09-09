#!/usr/bin/ruby
gets;a=$<.map{|e|e.split.map(&:to_i).reduce :+};p a[1..-1].count{|e|e>a[0]}+1
