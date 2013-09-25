#!/usr/bin/ruby
def dfs(d,width,*a)
	if d<5
		0.step(width){|e|dfs(d+1,width,*a,e)}
		dfs(d+1,width+1,*a,width+1)
	else
		blk=Array.new(width+1){[]}
		a.size.times{|i|blk[a[i]]<<i+1} #a[i]はインデックスiが入る箱の番号を表す
		puts blk.map(&:join)*'.'
	end
end
dfs(1,0,0)
#ショートコーディング版ではArray#maxを使っていて規則性を述べるには美しくないので、maxを除いたバージョン。