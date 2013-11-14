#!/usr/bin/ruby
p $<.drop(1).each_cons(2).count{|a,b|a!=b}+1