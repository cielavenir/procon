def recall_password(grille, template, openchar='X'):
	r=''
	for i in range(len(grille)):
		for j in range(len(grille)):
			if grille[i][j]==openchar: r+=template[i][j]
	if ord(template[0][0])&0x20 or ord(template[0][0])==1:
		for i in range(len(grille)):
			for j in range(len(grille)):
				if grille[len(grille)-1-j][i]==openchar: r+=template[i][j]
	else:
		for i in range(len(grille)):
			for j in range(len(grille)):
				if grille[j][len(grille)-1-i]==openchar: r+=template[i][j]
	for i in range(len(grille)):
		for j in range(len(grille)):
			if grille[len(grille)-1-i][len(grille)-1-j]==openchar: r+=template[i][j]
	if ord(template[0][0])&0x20 or ord(template[0][0])==1:
		for i in range(len(grille)):
			for j in range(len(grille)):
				if grille[j][len(grille)-1-i]==openchar: r+=template[i][j]
	else:
		for i in range(len(grille)):
			for j in range(len(grille)):
				if grille[len(grille)-1-j][i]==openchar: r+=template[i][j]
	return r

#old library cipher-map compatibility
checkio=lambda data:recall_password(*data)

if False:
	assert checkio([
		['X...',
		 '..X.',
		 'X..X',
		 '....'],
		['itdf',
		 'gdce',
		 'aton',
		 'qrdi']]) == 'icantforgetiddqd', 'First example'
	assert checkio([
		['....',
		 'X..X',
		 '.X..',
		 '...X'],
		['xhwc',
		 'rsqx',
		 'xqzz',
		 'fyzr']]) == 'rxqrwsfzxqxzhczy', 'Second example'
else:
	import sys
	if sys.version_info[0]>=3: raw_input=input
	n=int(raw_input())
	grille=[raw_input().strip() for _ in range(n)]
	text=raw_input().strip()
	_template=''.join(chr(i+1) for i in range(n*n))
	template=[_template[i*n:(i+1)*n] for i in range(n)]
	openchar='.'
	v=set()
	v2=[]
	for _ in range(4):
		for i in range(n):
			for j in range(n):
				if grille[i][j]==openchar:
					v.add((i,j))
					v2.append((i,j))
		grille=list(reversed(list(zip(*grille))))
	if len(v)!=n*n or len(v2)!=n*n:
		print('invalid grille')
	else:
		s=recall_password(grille,template,openchar)
		v=[None]*(n*n)
		for i in range(n*n):
			v[ord(s[i])-1]=i
		print(''.join(text[e] for e in v))