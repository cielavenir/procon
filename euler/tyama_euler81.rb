#!/usr/bin/ruby
#wget -O - https://projecteuler.net/project/resources/p081_matrix.txt
a=[]
#N=gets.to_i
N=80
while l=gets do a<<l.split(',').map(&:to_i) end
1.step(N-1){|i|a[0][i]+=a[0][i-1];a[i][0]+=a[i-1][0]}
1.step(N-1){|i|
	1.step(N-1){|j|
		a[i][j]+=[a[i-1][j],a[i][j-1]].min
	}
}
p a[N-1][N-1]