#!/usr/bin/python
import bisect,sys
if sys.version_info[0]>=3: raw_input=input

def checkio(data):
	se=[]
	for e in data:
		l,v=e
		r=l+v-1
		right_idx=bisect.bisect_left(se,(l,0)) #l <= se[right_idx][0]
		while l<=r:
			consumed=0
			if right_idx!=0:
				left_idx=right_idx-1
				if l<=se[left_idx][1]+1: # overlap with left
					consumed-=se[left_idx][1]-se[left_idx][0]+1
					l=se[left_idx][0]
					r=max(r,se[left_idx][1])
					#result-=se[left_idx][1]-se[left_idx][0]+1
					se.pop(left_idx)
					right_idx-=1
			while right_idx<len(se) and se[right_idx][0]<=r: # overlap with right
				consumed-=se[right_idx][1]-se[right_idx][0]+1
				r=max(r,se[right_idx][1])
				#result-=se[right_idx][1]-se[right_idx][0]+1
				se.pop(right_idx)
			#result+=r-l+1
			consumed+=r-l+1
			se.insert(right_idx,(l,r))
			right_idx+=1
			v-=consumed
			l=r+1
			r=l+v-1
		print(r)

N=int(raw_input())
a=[]
for _ in range(N):
	x,y=map(int,raw_input().split())
	a.append((x,y))
checkio(a)