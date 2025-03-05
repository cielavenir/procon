#!/usr/bin/ruby
r=eval s=gets
1.step(s.size){|i|s[i-1,2]=~/\d\d/&&r=[r,eval((s[i..-2]+s[0,i]).gsub /\d+/,&:to_i)].max}
p r
