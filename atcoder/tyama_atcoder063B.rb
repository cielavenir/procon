#!/usr/bin/ruby
w,h,n=gets.split.map(&:to_i)
M=(h+1).times.map{[0]*(w+1)}
n.times{
	a,b,c=gets.split.map(&:to_i)
	if c==1
		M[0][0]+=1
		M[0][a]-=1
		M[h][0]-=1
		M[h][a]+=1
	elsif c==2
		M[0][a]+=1
		M[0][w]-=1
		M[h][a]-=1
		M[h][w]+=1
	elsif c==3
		M[0][0]+=1
		M[0][w]-=1
		M[b][0]-=1
		M[b][w]+=1
	elsif c==4
		M[b][0]+=1
		M[b][w]-=1
		M[h][0]-=1
		M[h][w]+=1
	end
}
h.times{|i|(w+1).times{|j|M[i+1][j]+=M[i][j]}}
(h+1).times{|i|w.times{|j|M[i][j+1]+=M[i][j]}}
r=0
h.times{|i|w.times{|j|r+=M[i][j]==0 ? 0 : 1}}
p h*w-r
