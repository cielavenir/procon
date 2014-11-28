#!/usr/bin/python
#coding:utf-8
#derived from checkio painting-wall (presented by me)
#http://www.checkio.org/mission/painting-wall/share/8a0e0061de3ff95664776d904d309e57/
import bisect

def checkio(data):
	ret_idx=0
	result=0
	se=[]
	for l,r in data:
		ret_idx+=1
		right_idx=bisect.bisect_left(se,(l,0)) #l <= se[right_idx][0]
		if right_idx!=0:
			left_idx=right_idx-1
			if l<=se[left_idx][1]: # overlap with left
				l=se[left_idx][0]
				r=max(r,se[left_idx][1])
				result-=se[left_idx][1]-se[left_idx][0]+1
				se.pop(left_idx)
				right_idx-=1
		while right_idx<len(se) and se[right_idx][0]<=r: # overlap with right
			r=max(r,se[right_idx][1])
			result-=se[right_idx][1]-se[right_idx][0]+1
			se.pop(right_idx)
		result+=r-l+1
		se.insert(right_idx,(l,r))
	return result

if __name__ == '__main__':
	from collections import defaultdict
	import sys
	if sys.version_info[0]>=3: raw_input=input
	dic=defaultdict(list)
	n,d,t=[int(e) for e in raw_input().split()]
	for e in map(int,raw_input().split()):
		mod=e%d
		dic[mod].append(((e-mod)//d-t,(e-mod)//d+t))
	print(sum(checkio(v) for k,v in dic.items()))