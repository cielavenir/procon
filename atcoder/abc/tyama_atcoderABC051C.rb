#!/usr/bin/ruby
a,b,c,d=gets.split.map &:to_i;x=c-a;y=d-b;puts ?U*y+?R*x+?D*y+?L*(x+=1)+?U*(y+=1)+?R*x+'DR'+?D*y+?L*x+?U
