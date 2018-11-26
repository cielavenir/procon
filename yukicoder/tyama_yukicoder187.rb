#!/usr/bin/ruby
def egcd(x,y)
	return [x,1,0] if y==0
	g,a,b=egcd(y,x%y)
	[g,b,a-x/y*b]
end
def chinese(a)
	return nil if !a||a.empty?
	a.reduce{|(a1,m1),(a2,m2)|
		g,x,y=egcd(m1,m2)
		break if (a2-a1)%g>0
		l=m1/g*m2
		[(a1+(a2-a1)/g*x*m1)%l,l]
	}
end
r=chinese($<.drop(1).map{|e|e.split.map &:to_i})
p r ?r[r[0]==0?1:0]%1000000007:-1

__END__
f=->x,y{return[x,1,0]if y==0
g,a,b=f[y,x%y]
[g,b,a-x/y*b]}
gets
a=$<.map{|e|e.split.map &:to_i}
p (r=a.reduce{|(a,m),(b,n)|g,x,y=f[m,n]
(b-=a)%g>0&&break
n*=m/g
[(a+b/g*x*m)%n,n]})?r[r[0]>0?0:1]%(10**9+7):-1
#[(a+b/g*x*m)%n,n]})?r[~(0<=>r[0])]%(10**9+7):-1
