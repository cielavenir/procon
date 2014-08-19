#!/usr/bin/ruby
p$<.drop(1).map(&:to_i).sort[0..3].permutation(2).map{|a,b|(a.to_s+b.to_s).to_i}.sort[2]