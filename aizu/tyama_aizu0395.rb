#!/usr/bin/ruby
gets;a=$<.map{|e|e.split.map &:to_i}.transpose.partition{|a,b|a==1}.map{|e|e.map(&:last).min}.compact;p a[1]?a[0]+a[1]:0
