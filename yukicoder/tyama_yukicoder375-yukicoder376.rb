#!/usr/bin/ruby
m=N=gets.to_i
y=(1..N**0.5).select{|i|N%i==0}
y.map{|a|y.each{|b|N%(a*b)==0&&m=[m,a+b+N/a/b-3].min}}
$><<[m,N-1]*' '