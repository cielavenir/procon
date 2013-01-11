#!/usr/bin/ruby
A=["A","B","X","Y"];gets;x=gets.chomp;n=999;15.times{|i|(i+1).step(15){|j|n=[n,x.gsub(A[i/4]+A[i%4],"L").gsub(A[j/4]+A[j%4],"R").length].min}};puts n