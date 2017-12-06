#!/usr/bin/ruby
gets;A=$<.map{|e|e.split.map &:to_i}.sort_by{|x,y|x+y}
H=[0]
A.map{|x,y|(s=H.size-1).downto(0){|i|x>=H[i]&&(i==s&&H<<1e9;H[i+1]>H[i]+y&&H[i+1]=H[i]+y)}}
p H.size-1
#making temporary array is slow :(
