#!/usr/bin/ruby
S='SRL'
def dfs(a,x,y,s)
	if y==0
		puts s
		exit
	end
	[-1,0,1].each{|i|
		if 0<=x+i&&x+i<W && a[y-1][x+i]!='x'
			dfs(a,x+i,y-1,s+S[i])
		end
	}
end
H,W=gets.split.map &:to_i
a=$<.map &:chomp
dfs(a,a[-1].index('s'),H-1,'')
puts :impossible
