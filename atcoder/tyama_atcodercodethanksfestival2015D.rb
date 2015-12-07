#!/usr/bin/ruby
N=gets.to_i
know=Hash.new{|h,k|h[k]={}}
sum=Hash.new(0)
students=N.times.map{|i|know[i][i]=1;sum[i]=gets.to_i}
total=students.reduce(:+)
gets.to_i.times{
	a,b,c=gets.split.map(&:to_i)
	if a==0
		know[b-1][c-1]=1
		sum[b-1]+=students[c-1]
	else
		if know[b-1][c-1]
			puts '%d %d'%[students[c-1],students[c-1]]
		else
			remainsum=total-sum[b-1]
			remainnum=N-know[b-1].size
			puts '%d %d'%[[0,remainsum-100*(remainnum-1)].max,[100,remainsum].min]
		end
	end
}