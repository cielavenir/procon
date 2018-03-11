#!/usr/bin/ruby
N,M,Q=gets.split.map &:to_i
candidates=[*'a'..'z']
S='a'*M
s=S
h={S=>1}
(M...N).each{|i|
	t=s[1,M]
	c=candidates.shuffle.find{|e|!h.has_key?(t+e)}
	S<<c
	t<<c
	s=t
	h[s]=1
}
puts S
p 1
STDOUT.flush
S<<S
q=Q.times.map{gets.chomp}
Q.times{|i|p S.index(q[i])}
