#!/usr/bin/ruby
gets;a=[0]+$<.map(&:to_i);puts a.each_cons(2).all?{|x,y|(x-y).abs==1}?:T: :F
