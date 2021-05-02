#!/usr/bin/ruby
a=b=1;gets;$<.map{|e|x,y=e.split.map &:to_i;n=[~-a/x,~-b/y].max+1;a,b=n*x,n*y};p a+b
