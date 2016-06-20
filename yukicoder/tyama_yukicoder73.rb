#!/usr/bin/ruby
def comb(n,r)
	return 0 if n<r
	return (n-r+1..n).reduce(:*)/(1..r).reduce(:*)
end
h=Hash[[*'A'..'Z'].zip($<.map(&:to_i))]
if h['L']<3
	p 0
	exit
end
r=comb(h['H'],1)*comb(h['E'],1)*comb(h['O']/2,1)*comb(h['O']-h['O']/2,1)*comb(h['W'],1)*comb(h['R'],1)*comb(h['D'],1)
r*=2.step(h['L']-1).map{|e|comb(e,2)*comb(h['L']-e,1)}.max
p r