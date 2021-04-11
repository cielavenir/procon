#!/usr/bin/ruby
f=->(s,h,w,a,q){s[h+1][w+1]=s[h+1][w]+s[h][w+1]-s[h][w]+a[h][w]*q}
g=->(s,y1,x1,y2,x2){s[y2][x2]-s[y2][x1-1]-s[y1-1][x2]+s[y1-1][x1-1]}
H,W,N=gets.split.map &:to_i
a=H.times.map{gets.chomp.chars.map &:to_i}
s,s1,s2=3.times.map{(H+1).times.map{[0]*(W+1)}}
H.times{|h|W.times{|w|
	f[s,h,w,a,1]
	f[s1,h,w,a,w+1<W&&a[h][w+1]==1 ? 1 : 0]
	f[s2,h,w,a,h+1<H&&a[h+1][w]==1 ? 1 : 0]
}}
N.times{
	y1,x1,y2,x2=gets.split.map &:to_i
	p g[s,y1,x1,y2,x2]-g[s1,y1,x1,y2,x2-1]-g[s2,y1,x1,y2-1,x2]
}
