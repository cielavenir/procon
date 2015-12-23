#!/usr/bin/ruby
$memo={}
$memo2={}
def dfs(prev,cur,remain)
	if remain<0
		return -Float::INFINITY 
	elsif cur==W.size
		return remain>0 ? -Float::INFINITY : 0
	end
	$memo[prev*100000000+cur*10000+remain]||=[dfs(0,cur+1,remain),dfs(1,cur+1,remain-1)+W[cur-1]*prev].max
end
def dfs2(prev,cur,remain)
	if remain<0
		return -Float::INFINITY
	elsif cur==W.size
		return remain>0 ? -Float::INFINITY : W[cur-1]*prev
	end
	$memo2[prev*100000000+cur*10000+remain]||=[dfs2(0,cur+1,remain),dfs2(1,cur+1,remain-1)+W[cur-1]*prev].max
end
n,m,*W=$<.read.split.map(&:to_i)
if m<2
	p 0
	exit
else
	p [dfs(0,1,m),dfs2(1,1,m-1)].max
end