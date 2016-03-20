#!/usr/bin/ruby
gets;A=$<.map{|e|e.split.map &:to_f};p (0..1e9).bsearch{|t|[0,1].all?{|i|A.map{|e|e[i]-t/e[2]}.max<A.map{|e|e[i]+t/e[2]}.min}}