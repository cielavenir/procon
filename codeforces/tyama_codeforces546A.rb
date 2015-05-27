#!/usr/bin/env ruby
k,n,w=gets.split.map(&:to_i)
p [w*-~w/2*k-n,0].max