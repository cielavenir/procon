#!/usr/bin/ruby
x,y,r=gets.split.map{|i|i.to_i.abs}
p x+y+(r*1.414).ceil