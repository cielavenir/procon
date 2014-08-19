#!/usr/bin/ruby
while gets
n=$_.to_i-1
a=(n+1).times.map{gets.split(',').map(&:to_i)}
1.step(n){|i|a[0][i]+=a[0][i-1];a[i][0]+=a[i-1][0]}
1.step(n){|i|
	1.step(n){|j|
		a[i][j]+=[a[i-1][j],a[i][j-1]].min
	}
}
p a[n][n]
end