#!/usr/bin/ruby
n,*a=`dd`.split.map &:to_i
i=0;r=0;f=nil
a.each{|_|i+=1;f ?f=nil :_==i&&f=r+=1}
p r
