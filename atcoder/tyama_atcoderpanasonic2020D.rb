#!/usr/bin/ruby
F=->s,n,m{s.size==n ?puts(s):('a'..m).each{|c|F[s+c,n,c==m ?m.succ: m]}};F['',gets.to_i,'a']
