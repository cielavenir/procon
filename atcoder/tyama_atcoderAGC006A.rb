#!/usr/bin/ruby
n,s,t=`dd`.split;x=n.to_i;puts 2*x-x.downto(0).find{|i|s[-i,i]==t[0,i]}
