#!/usr/bin/ruby
s=gets;s=[0,2,4,3,1].map{|e|s[e]}*'';puts'%05d'%[s.to_i**5%100000]