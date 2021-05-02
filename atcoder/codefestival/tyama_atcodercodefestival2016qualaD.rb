#!/usr/bin/ruby
P=->s{puts s;exit};R,C=gets.split.map &:to_i;N=gets.to_i;M=Hash.new{|h,k|h[k]=[]}
N.times{x,y,d=gets.split.map &:to_i;M[x]<<[y+R,d];M[y+R]<<[x,-d]}
while !M.empty?
	a=-1e18;b=1e18;s=M.find{|e|e}[0];t=[[s,0]];m={s=>0}
	(x,d=t.pop;m[x]=d;M[x].map{|y,c|!m[y]?t<<[y,d+c]:m[y]!=d+c&&P[:No]};x<=R ? a=[a,d].max: b=[b,d].min)while !t.empty?
	a>b&&P[:No];m.map{|k,v|M.delete k}
end
P[:Yes]
