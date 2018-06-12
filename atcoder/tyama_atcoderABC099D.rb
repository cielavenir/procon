#!/usr/bin/ruby
g=->k{k.times.map{gets.split.map &:to_i}}
N,C=g[1][0];D=g[C];M=g[N];T=3.times.map{[0]*C}
N.times{|y|N.times{|x|T[(y+x)%3][M[y][x]-1]+=1}}
p [*0...C].permutation(3).map{|e|r=0;3.times{|i|C.times{|c|r+=T[i][c]*D[c][e[i]]}};r}.min
