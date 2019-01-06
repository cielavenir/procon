#!/usr/bin/ruby
h,w=gets.split.map &:to_i
a=[[-1]*(w+1)]
h.times{a<<[-1]+gets.chomp.chars.map{|c|c=='#'?-1:0}}
a[1][1]=1
(1..h).each{|i|(1..w).each{|j|a[i][j]=[a[i][j-1],0].max+[a[i-1][j],0].max if (i>1||j>1)&&a[i][j]>=0}}
p a[h][w]%(10**9+7)
