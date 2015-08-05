#!/usr/bin/ruby
N=gets.to_i
a=[-10**10]+gets.split.map(&:to_i)+[10**10]
1.step(N){|i|
	puts [[a[i]-a[i-1],a[i+1]-a[i]].min,[a[i]-a[1],a[N]-a[i]].max]*' '
}