#!/usr/bin/env python
#http://qiita.com/Nabetani/items/23ebddb44f0234e7fb15
#http://nabetani.sakura.ne.jp/hena/ord28spirwa/

D=( #Right,Up,Left,Down
	(0,1),
	(-1,0),
	(0,-1),
	(1,0),
)
dir=['E','N','W','S']

class Maze:
	def __init__(self,x,y,d,v):
		self.x=x
		self.y=y
		self.d=d
		self.v=v
		self.v[self.y][self.x]='*'
		self.route=[]
		self.route.append((self.x,self.y))
	def move(self):
		d_orig=(self.d+3)%4
		for i in range(4):
			self.d=(d_orig+i)%4
			if self.v[self.y+D[self.d][0]][self.x+D[self.d][1]]=='.': break
		self.y=self.y+D[self.d][0]
		self.x=self.x+D[self.d][1]
		self.v[self.y][self.x]='*'
		self.route.append((self.x,self.y))

if __name__=='__main__':
	import sys
	if sys.version_info[0]>=3: raw_input=input
	Z=100
	try:
		while True:
			line=raw_input().rstrip().split(':')
			n,e,s,w=[int(e) for e in line[0].split(',')]
			days=int(line[1])
			m=[['.']*(Z*2) for i in range(Z*2)]
			m[Z][Z]='*'
			for i in range(n): m[Z-i-1][Z]='*'
			for i in range(e): m[Z][Z+i+1]='*'
			for i in range(s): m[Z+i+1][Z]='*'
			for i in range(w): m[Z][Z-i-1]='*'
			maze=Maze(Z+1,Z-1,0,m)
			for i in range(days+1):maze.move()
			print(dir[maze.d])
			sys.stdout.flush()
	except EOFError:
		pass