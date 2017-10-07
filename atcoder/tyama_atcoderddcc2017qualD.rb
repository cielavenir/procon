#!/usr/bin/ruby
H,W=gets.split.map &:to_i
A,B=gets.split.map &:to_i
c=0
m=$<.map{|e|s=e.chomp;c+=s.count(?S);s}
k1=k2=k3=0
(H/2).times{|i|(W/2).times{|j|
zi=H-i-1;zj=W-j-1;b=0
b|=1 if m[i][j]==?S
b|=2 if m[zi][j]==?S
b|=4 if m[i][zj]==?S
b|=8 if m[zi][zj]==?S
if b==15
	k3+=1
else
	k1+=1 if b&3==3||b&12==12
	k2+=1 if b&5==5||b&10==10
end}}
f=->k,a,b{
r=k3*([a,b].max+a+b)+k*a
r+=a if k3*4+k*2!=c
r+=b if k3*4!=c
r}
p [f[k1,A,B],f[k2,B,A]].max
