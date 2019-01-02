#!/usr/bin/ruby
require'prime'
D='〇一二三四五六七八九'
N=->s{
	r=q=d=0
	s.chars{|c|
		(k=D.index c)&&d=k
		[[1000,'千'],[100,'百'],[10,'十']].map{|u,v|c==v&&(d<1&&d=1;q+=u*d;d=0)}
		[[10**8,'億'],[10**4,'万']].map{|u,v|c==v&&(r+=(q+d)*u;q=d=0)}
	}
	r+q+d
}
J=->n{
	return'〇'if n<1
	s=''
	[[10**8,'億'],[10**4,'万'],[1,'']].map{|u,v|
		if 0<k=n/u%10000
			[[1000,'千'],[100,'百'],[10,'十'],[1,'']].map{|u,v|0<(l=k/u%10)&&(l>=(u>9?2:1)&&s+=D[l];s+=v)};s+=v
		end
	}
	s
}
P=->x,y,m{
	f=x>=m
	z=1
	while y>0
		y%2>0&&z=z*x%m
		x*=x;f||=x>=m;x%=m
		y/=2
	end
	f ? z+m : z
}
totient=->n{s=1;n.prime_division.map{|n,p|s*=(n-1)*n**(p-1)};s}
M=10**9+9
q=[M]
st=[]
k=''
(gets.chomp+'の一乗').chars{|c|
	if c=='の'
		k[0]&&st<<N[k]&&k=''
	elsif c=='乗'
		k[0]&&st<<N[k]&&k=''
		q<<totient[q[-1]]while q.size<=st.size
		st<<P[*st.pop(2),q[st.size]]
	else
		k+=c
	end
}
puts J[st[0]%M]
