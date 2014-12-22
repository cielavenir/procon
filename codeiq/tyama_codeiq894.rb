#!/usr/bin/ruby
#領域について動的計画法を使おうと思いましたが、そうすると重複が出てくるので、全探索します。
#2**24通りなのでぎりぎり間に合うかと…。※44分かかりました。
require 'json'
N=4
D=[[0,1],[1,0],[0,-1],[-1,0]]
a=['*'*(N*2+1)]+['*'+' '*(N*2-1)+'*']*(N*2-1)+['*'*(N*2+1)]
nbar=2*N*(N-1)
result1=0
result2=0
(1<<nbar).times{|i|
	f1=f2=1
	b=JSON.parse(JSON.generate(a))
	(nbar/2).times{|j|
		if i&(1<<j)!=0
			b[j/N*2+2][j%N*2+1]='*'
		end
	}
	(nbar/2).times{|j|
		if i&(1<<(j+nbar/2))!=0
			b[j%N*2+1][j/N*2+2]='*'
		end
	}
	(N-1).times{|i|
		(N-1).times{|j|
			if 4.times.any?{|k|
				b[i*2+2+D[k][0]][j*2+2+D[k][1]]=='*'
			}
				b[i*2+2][j*2+2]='*'
			end
		}
	}
	#Now b represents cell. Let's validate it.
	N.times{|i|
		N.times{|j|
			if b[i*2+1-1][j*2+1]!='*' || b[i*2+1][j*2+1-1]!='*'
				next
			end
			k=0
			while b[(i+k)*2+1+1][j*2+1]!='*'
				k+=1
			end
			k+=1
			l=0
			loop{
				if b[(i+0)*2+1-1][(j+l)*2+1]==' '
					f1=f2=0
				end
				if k.times.any?{|m|
					b[(i+m)*2+1+1][(j+l)*2+1]==(m<k-1 ? '*' : ' ')
				}
					f1=f2=0
				end
				if k.times.any?{|m|
					b[(i+m)*2+1][(j+l)*2+1+1]!=b[(i+0)*2+1][(j+l)*2+1+1]
				}
					f1=f2=0
				end
				if b[(i+0)*2+1][(j+l)*2+1+1]=='*'
					break
				end
				l+=1
			}
			if [k,l]==[1,0]
				f2=0
			end
		}
	}
	#b.each{|e|puts e}
	#p f1
	#p f2
	result1+=f1
	result2+=f2
}
p result1 # 70878
p result2 # 1208