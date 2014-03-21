import sys
if sys.version_info[0]>=3: raw_input=input

b=lambda s,c: ((s[0]==c and s[1]==c and s[2]==c)or(s[3]==c and s[4]==c and s[5]==c)or(s[6]==c and s[7]==c and s[8]==c)or(s[0]==c and s[3]==c and s[6]==c)or(s[1]==c and s[4]==c and s[7]==c)or(s[2]==c and s[5]==c and s[8]==c)or(s[0]==c and s[4]==c and s[8]==c)or(s[2]==c and s[4]==c and s[6]==c))

if __name__ == '__main__':
	a=''
	for i in range(3):
		a+=raw_input().rstrip().replace(' ','')
	print('BINGO!' if b(a,'1') else 'NO BINGO')