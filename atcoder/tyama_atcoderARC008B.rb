#!/usr/bin/ruby
gets;s=gets.chop;k=gets;p begin s.split('').uniq.map{|e|(s.count(e).to_f/k.count(e)).ceil}.max rescue -1 end