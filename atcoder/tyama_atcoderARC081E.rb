#!/usr/bin/ruby
S=gets.chop
n=S.size
L=[0]*n
l=[n]*26
(n-1).downto(0){|i|L[i]=l.dup;l[S[i].ord-97]=i}
L[-1]=l
q=[-1]
z={-1=>[nil,0]}
(v=q.shift;l=L[v];26.times{|c|!z[l[c]]&&(z[l[c]]=[v,c];q<<l[c])})while q[0]&&q[0]!=n
r=''
(n,c=z[n];r<<(c+97))while n
$><<r.reverse[1..-1]
