#!/usr/bin/ruby
m=eval *$<;n=(2..10**6).find{|i|m%i==0}||1;puts '%d %d'%[n,m/n]