#!/usr/bin/ruby
N=gets.to_i
M=10**9+7
C,F,P=3.times.map{(N+2).times.map{[0]*(N+2)}}
(0..N).each{|x|C[x][0]=F[x][1]=1
(1..x).each{|y|C[x][y]=(C[x-1][y]+C[x-1][y-1])%M;F[x][y]=(F[x-1][y-1]+y*F[x-1][y])%M}}
r=0
(0..N).each{|x|P[x][0]=1
(0..N).each{|y|P[x][y+1]=P[x][y]*x*~-x%M;r=(r+C[N][N-y]*F[N-y][x]*P[x][y])%M}}
p r