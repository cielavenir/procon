#!/usr/bin/ruby
#541
#Q=[0,6,40,213,1049,5034,23984]
#A=[9,-27,38,-29,11,1,-2]
#569
#Q=[1,8,38,184,976,5382,29739,163496,896476,4913258,26932712,147657866]
#A=[12,-54,124,-133,-16,175,-94,-69,40,12,-4,-1]
#578,579
#Q=[1,32,316,2292,14422,84744,479004,2638328,14258574,75940592,399782668,84795558]
#A=[16,-102,342,-685,884,-753,386,-62,-56,39,-4,-4]
#621
Q=[1,2,5,22,75,264,941,3286,11623,40960,144267,508812,1792981,6319994,22277291]
A=[1,5,11,5,14,8,3,0,-5,-11,-1,2,0,0,1]

M=10**9+7
def mul(a,b)
	r=a.size.times.map{[0]*b[0].size}
	a.size.times{|y|b[0].size.times{|x|r[y][x]=b.size.times.reduce(0){|s,i|(s+a[y][i]*b[i][x])%M}}}
	r
end
k=gets.to_i
k<Q.size&&(p Q[k];exit)
k-=Q.size-1
e=Q.size.times.map{|i|a=[0]*Q.size;a[i]=1;a}
a=[A,*e[0...-1]]
while k>0
	e=mul(e,a) if k%2>0
	a=mul(a,a)
	k/=2
end
p mul(e,[Q.reverse].transpose)[0][0]
