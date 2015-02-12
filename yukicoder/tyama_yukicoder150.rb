#!/usr/bin/ruby
puts$<.drop(1).map{|s|(0..s.size-12).map{|i|(i+4..s.size-8).map{|j|(0..10).count{|k|(s[i,4]+s[j,7])[k]!='goodproblem'[k]}}.min}.min}