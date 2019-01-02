#!/usr/bin/ruby
require'prime';D='〇一二三四五六七八九'
N=->s{r=q=d=0;s.chars{|c|(k=D.index c)&&d=k;[[1000,'千'],[100,'百'],[10,'十']].map{|u,v|c==v&&(d<1&&d=1;q+=u*d;d=0)};[[10**8,'億'],[10**4,'万']].map{|u,v|c==v&&(r+=(q+d)*u;q=d=0)}};r+q+d}
J=->n{return'〇'if n<1;s='';[[10**8,'億'],[10**4,'万'],[1,'']].map{|u,v|0<(k=n/u%10000)&&([[1000,'千'],[100,'百'],[10,'十'],[1,'']].map{|u,v|0<(l=k/u%10)&&(l>=(u>9?2:1)&&s+=D[l];s+=v)};s+=v)};s}
P=->x,y,m{f=x>=m;z=1;(y%2>0&&z=z*x%m;x*=x;f||=x>=m;x%=m;y/=2)while y>0;f ?z+m: z}
T=->n{s=1;n.prime_division.map{|n,p|s*=~-n*n**~-p};s}
q=[M=10**9+9];t=[];k=''
(gets.chomp+'の一乗').chars{|c|c=='の'?(k[0]&&t<<N[k]&&k=''):c=='乗'?(k[0]&&t<<N[k]&&k='';q<<T[q[-1]]while q.size<=t.size;t<<P[*t.pop(2),q[t.size]]):k+=c}
$><<J[t[0]%M]
