#!/usr/bin/ruby
a,b=$<.map{|e|e.chars.sort};puts a==b ?:YES: :NO