#!/usr/bin/ruby
#How could I "invent" this code? no way --;
T={'A'=>'U','C'=>'G','G'=>'C','U'=>'A'}
s=$<.drop(1).map(&:chomp)*''
a=Array.new(s.size+1){[1]*(s.size+1)}
0.step(s.size-1){|k|
	k.step(s.size-1){|j|
		i=j-k
		t=T[s[i,1]]
		sum=0
		(i+0).step(j){|l|
			sum+=a[i+1][l-1]*a[l+1][j] if t.index(s[l,1])
		}
		a[i][j]=sum
	}
}
p a[0][s.size-1]%10**6