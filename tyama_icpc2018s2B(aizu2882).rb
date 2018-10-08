#!/usr/bin/ruby
n=gets.to_i;z=0;500.times{|q|g=0;[100,50,10,5,1].map{|e|r,q=q.divmod e;g+=r};g<=n&&z+=1};p z
