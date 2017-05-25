#!/usr/bin/ruby
gets;c=0;p$<.map{|e|e.split.map &:to_i}.sort_by{|a,b|a<b ?a:1e10-b}.map{|a,b|b+c+=a-b}.max