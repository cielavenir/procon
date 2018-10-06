#!/usr/bin/ruby
#http://nabetani.sakura.ne.jp/hena/orde27cardgame/
#https://qiita.com/Nabetani/items/cdc102d186faaf542574

def dfs(a,msk)
	$memo[msk]||=->{
		idx_=(0...a.size).find{|i|msk[i]==0}
		if !idx_
			0
		else
			r=nil
			2.times{|k|
				idx=idx_
				add=1<<idx
				c=1
				while idx=(idx+1...a.size).find{|i|o=a[idx_].dup;o[k]+=c;a[i]==o&&msk[i]==0}
					add|=1<<idx
					r0=dfs(a,msk|add)
					if r0
						r=[r.to_i,c**2+r0].max
					end
					c+=1
				end
			}
			r
		end	
	}.()
end
while gets
	$memo={}
	a=$_.chomp.split(',').map{|e|[e[0].ord-65,e[1].ord-49]}.sort
	puts dfs(a,0)||'-'
	STDOUT.flush
end
