#!/usr/bin/ruby
$a=[*2..5]
def dfs(x,d,dotted,f)
	if d==5
		puts x.join('').gsub('-9','.')
	else
		if x.last<0
			$a.each{|e|
				if !x.include?(e)&&(dotted.last||0)<e
					dfs(x+[e],d+1,dotted+[e],true)
				end
			}
		else
			(x.last+1).step($a.last){|i|
				if !x.include?(i)
					dfs(x+[i],d+1,dotted,false)
				end
			}
			dfs(x+[-9],d,dotted,true)
		end
	end
end
dfs([1],1,[],false)