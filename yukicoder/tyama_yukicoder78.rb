#!/usr/bin/ruby
N,K=gets.split.map(&:to_i)
S=gets.chomp.chars.map(&:to_i)

#phase1: brute force
buy=[0]*(N+1)
atari=0
1.step(N){|i|
	if atari==0
		atari+=1
		buy[i]=1
	end
	buy[i]+=buy[i-1]
	atari+=S[i-1]-1
}

d,r=(K-1).divmod(N)
r+=1
if d==0
	p buy[r]
else
	#phase2: use multiply
	p buy[-1]+(d-1)*[buy[-1]-atari,0].max+[buy[r]-atari,0].max
end