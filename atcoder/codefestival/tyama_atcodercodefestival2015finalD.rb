#!/usr/bin/ruby
M=10**5+1
S=[0]*M
N=gets.to_i
A=N.times.map{
	a=gets.split.map(&:to_i)
	S[a[0]]+=1
	S[a[1]]-=1
	a
}
1.upto(M-1){|i|S[i]+=S[i-1]}
ma=S.max
l,r=M.times.select{|i|S[i]==ma}.minmax
p ma-(A.any?{|x,y|x<=l&&r<y}?1:0)