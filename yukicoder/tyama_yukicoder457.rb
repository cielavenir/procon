#!/usr/bin/ruby
def solve(s)
	len=s.size
	al=[]
	ar=[]
	ah=[0]*len
	ast=[]
	len.times{|i|
		if s[i]==?(
			al<<i
		elsif s[i]==?)
			ar<<i
		elsif s[i]==?^
			ah[i]+=1
		elsif s[i]==?*
			ast<<i
		end
	}
	(1...s.size).each{|i|ah[i]+=ah[i-1]}
	ret=0
	al.each{|l|
		hidx=(l...len).bsearch{|i|ah[i]>=ah[l]+2}||len
		st=ast.bsearch{|e|e>=hidx}
		break if !st
		ret+=ar.size-((0...ar.size).bsearch{|i|ar[i]>=st}||ar.size)
	}
	ret
end
s=gets.chomp
puts [solve(s),solve(s.reverse.tr('()',')('))]*' '
