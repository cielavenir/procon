#!/usr/bin/ruby
$m=0
$c=0
$n,m=gets.split.map(&:to_i)
def dfs(a,sa,sb,i)
	i.step(a.size-1){|j|
		sa_=sa+a[i][0]
		if sa_<=$n
			sb_=sb+a[i][1]
			$m=sb_ if sb_>$m
			$c+=1
			if $c==16500
				p $m
				exit
			end
			dfs(a,sa_,sb_,j+1)
		end
	}
end
a=m.times.map{gets.split.map(&:to_i)}.sort_by{|e|e[0].to_f/e[1]}
dfs(a,0,0,0)
p $m