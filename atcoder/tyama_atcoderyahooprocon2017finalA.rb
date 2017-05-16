#!/usr/bin/ruby
T='yahoo';S=gets.chomp;a=[*1..4,0];S.size.times{|i|b=a.dup;5.times{|j|x=S[i]==T[j]?0:1;b[j]=a[j]+1;5.times{|k|b[j]=[b[j],a[k]+(j-k+4)%5+x].min}};a=b};p a[4]