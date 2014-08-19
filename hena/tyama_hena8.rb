#!/usr/bin/env ruby
#http://qiita.com/Nabetani/items/709d61dff282cff7a890
#http://nabetani.sakura.ne.jp/hena/ord8biboma/
require 'json'
D=[[-1,0],[1,0],[0,-1],[0,1]]
def dfs(x,y,i)
	if 0<=x&&x<6&&0<=y&&y<5&&$wall[y][x]==0
		$result[y][x]=1
		dfs(x+D[i][0],y+D[i][1],i)
	end
end
STDOUT.sync=true
while gets
	$wall,bomb=$_.split('/').map{|e|sprintf('%032b',e.to_i(16))[0,30].chars.map(&:to_i).each_slice(6).to_a}
	$result=JSON.parse(JSON.generate(bomb)) #deep copy
	bomb.size.times{|y|
		bomb[0].size.times{|x|
			if bomb[y][x]==1
				D.size.times{|i|dfs(x+D[i][0],y+D[i][1],i)}
			end
		}
	}
	puts sprintf('%08x',($result.map(&:join)*''+'00').to_i(2))
end