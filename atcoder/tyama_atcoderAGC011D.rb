#!/usr/bin/ruby
n,k=gets.split.map &:to_i
s=gets.chomp.chars.map{|c|c==?A?0:1}
f=i=0
((~s[i]+f)%2>0?s[i]=1-f :(s[n+i]=f^=1;i+=1);k-=1)while i<n&&k>0
puts k>0?['',[?B,?A][(~s[i]+f+k)%2]][n%2]+'BA'*(n/2):s[i,n].map{|c|[?B,?A][(~c+f)%2]}*''
