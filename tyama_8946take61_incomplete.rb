#!/usr/bin/ruby
#coding:utf-8
T=' etaoinshrdlcumwfgypbvkjxqz'
h=Hash.new(0)
s=$<.read
s.chars{|c|h[c]+=1}
h.delete("\n")
h.delete("\r")
freq=h.sort_by{|e|-e.last}
p freq
#p s.tr(freq.map(&:first)[0,T.size]*'',T)