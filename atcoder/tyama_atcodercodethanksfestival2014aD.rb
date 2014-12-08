#!/usr/bin/ruby
def solve(a,b,s,t)
	if b<s || t<a
		t-s
	elsif a<=s && t<=b
		0
	elsif a<=s
		t-b
	elsif t<=b
		a-s
	else
		t-s-(b-a)
	end
end

n,q=gets.split.map(&:to_i)
q.times{
	a,b,s,t=gets.split.map(&:to_i)
	p solve(a,b,s,t)*100
}