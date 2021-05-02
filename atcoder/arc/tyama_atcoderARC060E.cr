#!/usr/bin/env crystal

z=ARGF.gets_to_end.lines.map{|e|e.split.map &.to_i}
n=z.shift[0]
a=z.shift
l=z.shift[0]
q=z.shift[0]
m=Array.new(n){[0]*17}+[[n]*17]
(n-1).times{|i|m[i][0]=((0...n).bsearch{|j|a[j]>a[i]+l}||n)-1}
m[n-1][0]=n
(n-1).downto(0){|i|1.upto(16){|j|m[i][j]=m[m[i][j-1]][j-1]}}
z.map{|a|x,y=a.sort;x-=1;y-=1;s=1;16.downto(0){|i|m[x][i]<y&&(x=m[x][i];s+=1<<i)};p s}
