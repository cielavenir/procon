#!/usr/bin/ruby
_,a,b=$<.map{|e|e.split.map(&:to_i).reduce :+};puts a<b ? :No : :Yes
