#!/usr/bin/ruby
n,m,*A=gets.split.map(&:to_i)
if n>m then n,m=m,n end
# now n<=m is assurred
if n==2
	p m-2
elsif m>4 #strategy 1
	p ((m-1)/2*2)+((n-1)/2*2)
else #strategy 2
	if n==3&&m==3
		if A==[0,0]
			puts 3
		elsif A==[1,0]
			puts 0
		elsif A==[0,1]
			puts 4
		else
			raise
		end
	elsif n==3&&m==4
		if A==[0,0]
			puts 4
		elsif A==[1,0]
			puts 2
		elsif A==[0,1]
			puts 4
		elsif A==[2,0]
			puts 0
		elsif A==[1,1]
			puts 3
		elsif A==[0,2]
			puts 4
		else
			raise
		end
	elsif n==4&&m==4
		if A==[0,0]
			puts 4
		elsif A==[1,0]
			puts 4
		elsif A==[0,1]
			puts 4
		elsif A==[2,0]
			puts 2
		elsif A==[1,1]
			puts 4
		elsif A==[0,2]
			puts 4
		elsif A==[3,0]
			puts 0
		elsif A==[2,1]
			puts 3
		elsif A==[1,2]
			puts 4
		elsif A==[0,3]
			puts 4
		elsif A==[4,0]
			puts 0
		elsif A==[3,1]
			puts 0
		elsif A==[2,2]
			puts 4
		elsif A==[1,3]
			puts 4
		elsif A==[0,4]
			puts 4
		else
			raise
		end
	else
		raise
	end
end