#!/usr/bin/ruby
$r={}
def dfs(h,s,cur)
	if h.size==0 then $r[s[-($k-1)..-1]+s[0..-$k]]=1;return end
	return if !h.has_key?(cur)
	#dest=h[cur].dup
	#dest.each_with_index{|e,i|
	h[cur].length.times{
		e=h[cur].delete_at(0)
		h.delete(cur) if h[cur].size==0
		dfs(h,s+cur[-1,1],e)
		h[cur]<<e
	}
end
a=[]
while gets
a<<$_.chomp
end
l=a[0].length
$k=l-1
h=Hash.new{|h,k|h[k]=[]}
#de Brujin graph
s=a.shift
a.each{|s|h[s[0,$k]]<<s[1,$k]}
cur=s[0,$k]
e=s[1,$k]
dfs(h,cur[-1,1],e)
$r.each_key{|e|puts e}