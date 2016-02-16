#!/usr/bin/ruby
a=gets.chars.chunk{|c|c=='ｗ'}.drop_while{|k,v|k==true}.each_slice(2).with_index.map{|((a,b),(c,d)),i|[-(d||[]).size,i,b*'']}.sort
puts a.take_while{|x,y|x==[a[0][0],-1].min}.map(&:last)