#!/usr/bin/env ruby
#https://gist.github.com/mattsan/07674b095908fda117a0

LINES=['AFGD','AJIC','BJFE','BIHD','CHGE']

def dfs(line,d,cur,color)
	return false if cur==-1||cur==line.size
	return true if $colors[line[cur]]==color
	$colors[line[cur]]=color if dfs(line,d,cur+d,color)
end
		
if __FILE__==$0
	while gets
		$colors=Hash[*('A'..'E').flat_map{|e|[e,0]}+('F'..'J').flat_map{|e|[e,1]}]
		$_.chomp.chars{|c|
			$colors[c]^=1
			LINES.each{|l|
				idx=l.index(c)
				if idx
					dfs(l,1,idx+1,$colors[c])
					dfs(l,-1,idx-1,$colors[c])
				end
			}
		}
		puts ('A'..'J').map{|e|'WR'[$colors[e],1]}*''
		STDOUT.flush
	end
end