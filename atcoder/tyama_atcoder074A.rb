#!/usr/bin/ruby
a,b=gets.split.map{|e|(Time.new(0,e.to_i%12+1)-1).day};puts a==b ?:Yes: :No
