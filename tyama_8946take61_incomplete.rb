#!/usr/bin/ruby
#coding:utf-8
S='bddsowntdntdtthnhynhjweoaaabtmntdaaatddbtbnhjsefbbdsetvsdweontd'
#T='etaoinshrdlcumwfgypbvkjxqz'
T='enisratdhulgcomwbfkzvpjyxq'
h=Hash.new(0)
s=$<.read.gsub('aaa',' ')
s.chars{|c|h[c]+=1}
h.delete("\n")
h.delete("\r")
h.delete("\t")
h.delete(" ")
h.delete(".")
h.delete(",")
h.delete("(")
h.delete(")")
h.delete("-")
freq=h.sort_by{|e|-e.last}
p freq
#p s.tr(freq.map(&:first)[0,T.size]*'',T)
p S.gsub('aaa',' ').tr(freq.map(&:first)[0,T.size]*'',T)