#!/usr/bin/ruby
require'prime';i=r=0;puts Prime.each{|p|r+=p;i+=1;if i==1000 then puts r;exit end}