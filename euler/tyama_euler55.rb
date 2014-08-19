#!/usr/bin/ruby
p 10000.times.count{|i|n=i;50.times.all?{n+=n.to_s.reverse.to_i;n.to_s!=n.to_s.reverse}}