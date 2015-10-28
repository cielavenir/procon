#!/usr/bin/ruby
def checkio(data)
	result=0
	se=[]
	data.each{|l,r|
		right_idx=(0...se.size).bsearch{|i|([l,0]<=>se[i])<=0}||se.size #l <= se[right][0]
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
		se.insert(right_idx,[l,r])
	}
	return result
end

if __FILE__ == $0
	dic=Hash.new{|h,k|h[k]=[]}
	n,d,t=gets.split.map(&:to_i)
	gets.split.map(&:to_i).each{|e|
		mod=e%d
		dic[mod]<<[e/d-t,e/d+t]
	}
	p dic.reduce(0){|s,(k,v)|s+checkio(v)}
end