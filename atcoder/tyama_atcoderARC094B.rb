#!/usr/bin/ruby
a,b,k=gets.split.map &:to_i
p *([*a..[a+k-1,b].min]+[*[a,b-k+1].max..b]).uniq
