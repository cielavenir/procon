#!/usr/bin/ruby
def dfs(a)
	r=0
	0.upto(a.size-3){|i|
		next if a[i]=='0'
		(i+1).upto(a.size-2){|j|
			next if a[i]==a[j]
			(j+1).upto(a.size-1){|k|
				if a[j]==a[k]
					b=a.dup
					[k,j,i].each{|e|b.delete_at(e)}
					r=[r,(a[i]+a[j]+a[k]).to_i+dfs(b)].max
				end
			}
		}
	}
	r
end
p dfs(gets.chomp.chars)
