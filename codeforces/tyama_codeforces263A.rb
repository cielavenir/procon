#!/usr/bin/ruby
d,r=$<.read.split.each_with_index.find{|e,i|e==?1}[1].divmod(5)
p (d-2).abs+(r-2).abs