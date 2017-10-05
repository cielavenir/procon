#!/usr/bin/ruby
n=gets.to_i;s=gets;q=0
p n.times.find{|i|if s[i]==?x;q+=1 else q=0 end;q>1}||n
