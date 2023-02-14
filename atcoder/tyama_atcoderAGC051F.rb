#!/usr/bin/ruby
L=[],[]
e=[1,1],[1,0];24.times{|i|x,z=e;L[i&1]<<x;L[i+1&1]<<[x[1]*2,x[0]];e=[2*x[0]+z[0],2*x[1]+z[1]],x}
L[0].map! &:reverse
G=->x,y,l{l.any?{|a,b|[[x-a,y],[x-2*a,y-b]].any?{|c,d|c>=0&&-~d/2*a<=c/2*b}}}
F=->x,y{x<0?G[y,-x,L[0]]:y>=0||G[x,-y,L[1]]}
gets;$<.map{|_|x,y=_.split.map &:to_i;puts F[x,y]?:Yes: :No}
