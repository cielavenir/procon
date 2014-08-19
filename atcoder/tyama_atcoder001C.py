D=[[0,1],[1,-1],[1,0],[1,1]]
def grid(m):
	for i in range(1,9):
		for j in range(1,9):
			if m[i][j]=='Q':
				for k in range(4):
					l=1
					while m[i+D[k][0]*l][j+D[k][1]*l]!='-':
						if m[i+D[k][0]*l][j+D[k][1]*l]=='Q': return False
						l+=1
	return True

def dfs(depth,m):
	if not grid(m): return None
	if depth==8: return m
	for i in range(1,9):
		for j in range(1,9):
			if m[i][j]!='Q':
				m[i][j]='Q'
				if dfs(depth+1,m): return m
				m[i][j]='.'
	return None

def place_queens(queens):
	m=[list('----------')]+[list('-........-') for i in range(10)]+[list('----------')]
	for e in queens:
		m[ord(e[0])-ord('`')][ord(e[1])-ord('0')]='Q'
	r=dfs(len(queens),m)
	if r:
		ret=set()
		for i in range(1,9):
			for j in range(1,9):
				if m[i][j]=='Q':
					ret.add(chr(96+i)+chr(48+j))
		return ret
	else:
		return set()

if False:
	import sys
	if sys.version_info[0]>=3: raw_input=input
	m=[list('----------')]
	for i in range(8):
		m.append(list('-'+raw_input().rstrip()+'-'))
	m.append(list('----------'))
	r=dfs(3,m)
	if r:
		for i in range(1,9): print(''.join(r[i][1:9]))
	else:
		print("No Answer")
else:
	assert place_queens({"b1", "c4", "d6", "e8"}) != {}
	assert place_queens({"b1", "c4", "d6", "e8", "a7", "g5"}) == set()