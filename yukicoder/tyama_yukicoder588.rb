#!/usr/bin/ruby
def f(a,b)
	return 0 if a<0 || S.size<=b
	f(a-1,b+1)+(S[a]==S[b] ? 2 : 0)
end
S=gets.chomp
r=0
(0...S.size).each{|i|r=[r,1+f(i-1,i+1)].max}
(0...S.size-1).each{|i|r=[r,f(i,i+1)].max}
p r
