#!/usr/bin/env crystal
def checkio(data)
	result=0

ifdef uncompiled # no bsearch in Crystal? lol
	se=[] of Tuple(Int64,Int64)
	data.each{|l,r|
		right_idx=(0...se.size).bsearch{|i|
			x={l,0}<=>se[i]
			x<=0
		}||se.size #l <= se[right][0]
		if right_idx!=0
			left_idx=right_idx-1
			if l<=se[left_idx][1]+1 # overlap with left
				l=se[left_idx][0]
				r=[r,se[left_idx][1]].max
				result-=se[left_idx][1]-se[left_idx][0]+1
				se.delete_at(left_idx)
				right_idx-=1
			end
		end
		while right_idx<se.size && se[right_idx][0]<=r # overlap with right
			r=[r,se[right_idx][1]].max
			result-=se[right_idx][1]-se[right_idx][0]+1
			se.delete_at(right_idx)
		end
		result+=r-l+1
		se.insert(right_idx,{l,r})
	}
end

	return result
end

dic={} of Int64 => Array(Tuple(Int64,Int64))
n,d,t=gets.not_nil!.split.map(&.to_i64)
gets.not_nil!.split.map(&.to_i64).each{|e|
	mod=e%d
	dic[mod]=[] of Tuple(Int64,Int64)
	dic[mod]<<{e/d-t,e/d+t}
}
p dic.inject(0_i64){|s,k,v|s+checkio(v)}