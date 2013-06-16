#!/usr/bin/ruby
a=$<.drop(1).map(&:chomp)
1.step(a.size-1){|i|if a[i][0..0]!=a[i-1][-1,1]||a[0,i].index(a[i]) then puts [:LOSE,:WIN][i&1];exit end}
puts :DRAW