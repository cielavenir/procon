#!/usr/bin/ruby
def dfs(ptr,coor,dir)
	return coor if ptr==@s.size
	return dfs(ptr+1,coor,-dir) if @s[ptr]=='T'
	return dfs(ptr+1,coor+dir,dir) if @s[ptr]=='F'
	return @memo[[ptr,coor,dir]]||=[dfs(ptr+1,coor+dir,dir),dfs(ptr+1,coor,-dir)].max
end
@s=gets.chomp
@memo={}
p dfs(0,0,1)