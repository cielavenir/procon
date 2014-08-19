#!/usr/bin/ruby
n,m=gets.split;puts n.to_i.times.map{gets}.reverse.uniq[0,m.to_i]*''