#!/usr/bin/ruby
a=[];k=0
(2*n=gets.to_i).times{|i|a=[a.map{'%*d'%["#{n*n}".size,k+=1]}]+a.transpose.reverse}
puts a.map{|e|e*' '}