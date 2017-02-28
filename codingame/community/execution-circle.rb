#!/usr/bin/ruby
n,m=gets.split.map &:to_i
d=gets.chomp
if true
	q=1
	q*=2 while q*2<n
	r=(2*(n-q)-1)%n+1
	r=n-r if d=='RIGHT'
	p (r+m)%n
else
	m=m+(d=='LEFT'?1:-1)
	k=d=='LEFT'?2:-1
	r=0
	1.step(n-1){|i|r=(r+k)%i}
	p (r+m)%n+1
end
