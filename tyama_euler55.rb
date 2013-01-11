#!/usr/bin/ruby
p 10000.times.select{|i|n=i;50.times.all?{n+=n.to_s.reverse.to_i;n.to_s!=n.to_s.reverse}}.count
#select{|i|i.to_s==i.to_s.reverse}.