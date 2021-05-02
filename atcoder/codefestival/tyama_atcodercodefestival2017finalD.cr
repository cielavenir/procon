#!/usr/bin/env crystal
n=gets.not_nil!.to_i;a=n.times.map{|e|gets.not_nil!.split.map &.to_i}.to_a.sort_by{|(x,y)|x+y}
H=[0]
a.map{|(x,y)|(s=H.size-1).downto(0){|i|x>=H[i]&&(i==s&&H<<10**9;H[i+1]>H[i]+y&&(H[i+1]=H[i]+y))}}
p H.size-1
