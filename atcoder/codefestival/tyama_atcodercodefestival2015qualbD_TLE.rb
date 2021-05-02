#!/usr/bin/ruby

def checkio(data)
	result=0
	se=[]
	data.each{|l,v|
		r=l+v-1
		right_idx=(0...se.size).bsearch{|i|([l,0]<=>se[i])<=0}||se.size #l <= se[right][0]
		while l<=r
			consumed=0
			if right_idx!=0
				left_idx=right_idx-1
				if l<=se[left_idx][1]+1 # overlap with left
					consumed-=se[left_idx][1]-se[left_idx][0]+1
					l=se[left_idx][0]
					r=[r,se[left_idx][1]].max
					result-=se[left_idx][1]-se[left_idx][0]+1
					se.delete_at(left_idx)
					right_idx-=1
				end
			end
			while right_idx<se.size && se[right_idx][0]<=r # overlap with right
				consumed-=se[right_idx][1]-se[right_idx][0]+1
				r=[r,se[right_idx][1]].max
				result-=se[right_idx][1]-se[right_idx][0]+1
				se.delete_at(right_idx)
			end
			#result+=l-r+1
			consumed+=r-l+1
			se.insert(right_idx,[l,r])
			right_idx+=1
			v-=consumed
			l=r+1
			r=l+v-1
		end
		p r
	}
end

if __FILE__==$0
	checkio(gets.to_i.times.map{gets.split.map(&:to_i)})
end