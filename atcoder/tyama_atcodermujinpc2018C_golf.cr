#!/usr/bin/env crystal
gets;a=ARGF.gets_to_end.split.map(&.chars).to_a;r=0_i64;[a,a.reverse.transpose,a.reverse.map &.reverse,a.transpose.reverse].map{|b|h=b.size;w=b[0].size;c=h.times.map{|e|[0]*w}.to_a;d=c.map(&.dup).to_a;(h-1).downto(0){|y|(w-1).downto(0){|x|c[y][x]=b[y][x]=='#'?-1: x==w-1?0: c[y][x+1]+1}};(w-1).downto(0){|x|(h-1).downto(0){|y|d[y][x]=b[y][x]=='#'?-1: y==h-1?0: d[y+1][x]+1}};(h-1).downto(0){|y|(w-1).downto(0){|x|r+=c[y][x]*d[y][x]if c[y][x]>0&&d[y][x]>0}}};p r