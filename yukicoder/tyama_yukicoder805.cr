#!/usr/bin/env crystal
r=0
n=gets.not_nil!.to_i
s=gets.not_nil!.chomp
n.times{|i|(i+2).step(to: n-1,by: 2){|j|k=i+(j-i)//2;s[i]=='U'&&s[k]=='M'&&s[j]=='G'&&(r+=1)}}
p r
