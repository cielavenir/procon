#!/usr/bin/ruby
n,m,k=gets.split.map(&:to_i)
raise if n>12
d0=(n-1).times.map{gets.to_i}
a=n.times.map{[0]*n}
0.step(n-2){|i|a[i+1][i]=a[i][i+1]=d0[i]}
2.step(n-1){|i|
	(i-2).downto(0){|j|
		a[i][j]=a[j][i]=a[i-1][j]+a[i-1][i]
	}
}
p [*0...n].permutation(k).count{|b|
	b.each_cons(2).map{|x,y|a[x][y]}.reduce(:+)%m==0
}%1000000007