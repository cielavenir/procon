#!/usr/bin/ruby
(N,),A,(L,),(Q,),*Z=`dd`.lines.map{|e|e.split.map &:to_i}
M=N.times.map{[0]*17}+[[N]*17]
(N-1).times{|i|M[i][0]=((0...N).bsearch{|j|A[j]>A[i]+L}||N)-1}
M[N-1][0]=N
(N-1).downto(0){|i|1.upto(16){|j|M[i][j]=M[M[i][j-1]][j-1]}}
Z.map{|a|x,y=a.sort;x-=1;y-=1;s=1;16.downto(0){|i|M[x][i]<y&&(x=M[x][i];s+=1<<i)};p s}