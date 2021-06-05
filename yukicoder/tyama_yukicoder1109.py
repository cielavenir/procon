#!/usr/bin/python
#coding:utf-8
#CodeIQ "Detect Music Key"やらCheckiO "Rotate Hole"やらで既出.此方の関数はCheckiOのコピー.
rotate=lambda state,pipe_numbers: [i for i in range(len(state)) if all(state[j%len(state)] or (i+j)%len(state) not in set(pipe_numbers) for j in range(len(state)))]

if __name__=='__main__':
	state=[1,0,1,0,1,1,0,1,0,1,0,1]
	import sys
	r=rotate(state,[int(e) for e in sys.stdin.read().split()[1:]])
	print(r[0] if len(r)==1 else -1)
