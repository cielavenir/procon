#!/usr/bin/ruby
gets;puts$<.sort_by{|e|e.split.zip([:to_i,:to_i,:to_s,:to_i,:to_s].map &:to_proc).map{|x,y|y[x]}}
