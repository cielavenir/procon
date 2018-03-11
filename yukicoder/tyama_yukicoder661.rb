#!/usr/bin/ruby
gets.to_i.times{n=gets.to_i;puts n%40==0 ? :ikisugi : n%8==0 ? :iki : n%10==0 ? :sugi : n/3}
