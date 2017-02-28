#!/usr/bin/ruby
require 'timeout'
T='<({['
S='>)}]'
M={}
def dfs(s,k,l)
	return true if k>l
	return M[[k,l]] if M.has_key?([k,l])
	M[[k,l]]=(k+1..l).any?{|idx|
		s[idx]==s[k]&&dfs(s,k+1,idx-1)&&dfs(s,idx+1,l)
	}
end
gets.to_i.times{
	M.clear
	s=gets.chomp.tr('^'+T+S,'').tr(S,T)
	begin
		timeout(5){
			p dfs(s,0,s.size-1)
		}
	rescue Timeout::Error
		p false
	end
}
