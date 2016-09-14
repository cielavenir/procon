#!/usr/bin/env crystal
#http://qiita.com/Nabetani/items/c516875b13a4d282affe
#http://nabetani.sakura.ne.jp/hena/orde05dokitruck/

T={
	1=>{0=>[0,1],1=>[1,2],2=>[2]},
	2=>{0=>[0,2],1=>[1],2=>[1,2]},
	3=>{0=>[0,2],1=>[0,1],2=>[2]},
	4=>{0=>[0],1=>[0,1],2=>[1,2]},
	5=>{0=>[0],1=>[1,2],2=>[0,2]},
	6=>{0=>[0,1],1=>[1],2=>[0,2]},
	7=>{0=>[0],1=>[nil],2=>[2]},
	8=>{0=>[nil],1=>[1],2=>[2]},
	9=>{0=>[0],1=>[1],2=>[nil]},
}

def dfs(d,cur,m,line)
	return true if d==line.size
	return m[[d,cur]] if m.has_key?([d,cur])
	m[[d,cur]]=T[line[d]][cur].any?{|e|e&&dfs(d+1,e,m,line)}
end

while line=gets
	line=line.chomp.chars.map(&.to_i)
	m=Hash(Array(Int32),Bool).new
	r=(0..2).select{|e|
		dfs(0,e,m,line)
	}.map{|e|(e+97).chr}.join
	puts r.empty? ? "-" : r
	STDOUT.flush
end
