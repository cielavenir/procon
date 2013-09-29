#!/usr/bin/ruby
require 'json'
def dfs(json)
	n=0
	if json.is_a?(Array)
		json.each{|e|n+=dfs(e)}
	elsif json.is_a?(Hash)
		json.each{|k,v|
			if k=='foo'
				n+=v
			else
				n+=dfs(v)
			end
		}
	end
	n
end
p dfs(JSON.parse($<.read))