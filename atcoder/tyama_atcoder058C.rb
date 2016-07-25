#!/usr/bin/ruby
s,x=gets.split;l=s.size-1;a=[*?0..?9]-gets.split
(puts s;exit)if !j=(0..l).find{|i|!a.find{|e|e==s[i]}}
k=j.downto(0).find{|i|x=a.find{|e|e>s[i]}}||-1
puts (k<0?a[0]>?0?a[0]:a[1]:s[0...k]+x)+a[0]*(l-k)