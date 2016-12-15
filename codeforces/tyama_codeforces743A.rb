#!/usr/bin/ruby
n,a,b,s=$<.read.split
p s[a.to_i-1]!=s[b.to_i-1] ? 1 : 0
