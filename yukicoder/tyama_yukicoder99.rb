#!/usr/bin/ruby
gets;s=0;gets.split.map{|e|s+=e.to_i%2*2-1};p s.abs