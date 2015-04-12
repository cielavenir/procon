#!/usr/bin/ruby
T=[
	[0,0,0,0,0],
	[0,1,2,3,4],
	[0,2,-1,4,-3],
	[0,3,-4,-1,2],
	[0,4,3,-2,-1],
]
def dfs2(d,cur)
	return false if d==$s.size
	sign=cur<0 ? -1 : 1
	nxt=sign*T[cur.abs][$s[d]]
	if nxt==3 && $tail[d+1]==4
		return true
	end
	return dfs2(d+1,nxt)
end
gets.to_i.times{|i|
	STDERR.puts i
	print "Case ##{i+1}: "
	l,x=gets.split.map(&:to_i)
	$s=(gets.chomp*x).chars.map{|e|'01ijk'.index(e)}
	$head=[nil]*$s.size
	$head[0]=$s[0]
	1.upto($s.size-1){|i|
		sign=$head[i-1]<0 ? -1 : 1
		$head[i]=sign*T[$head[i-1].abs][$s[i]]
	}
	$tail=[nil]*$s.size
	$tail[$s.size-1]=$s[$s.size-1]
	($s.size-2).downto(0){|i|
		idx=(1..4).find{|j|T[j][$s[i]].abs==$tail[i+1].abs}
		mulsign=T[idx][$s[i]]*$tail[i+1]<0 ? -1 : 1
		$tail[i]=mulsign*idx
	}
	#p $head
	#p $tail
	puts $tail.include?(4)&&$s.size.times.any?{|i|$head[i]==2 && dfs2(i+1,1)} ? 'YES' : 'NO'
}