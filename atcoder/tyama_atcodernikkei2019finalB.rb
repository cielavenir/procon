#!/usr/bin/ruby
(n,m,_),x,y=$<.map{|e|e.split.map &:to_i}
puts [:Same,:Y,:X][n!=m ? n<=>m : x<=>y]
