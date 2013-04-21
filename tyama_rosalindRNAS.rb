#!/usr/bin/ruby
T={'A'=>'U','C'=>'G','G'=>'CU','U'=>'AG'}
s=gets.chomp
a=Array.new(s.size+1){[1]*(s.size+1)}
4.step(s.size-1){|k|
	k.step(s.size-1){|j|
		i=j-k
		t=T[s[i,1]]
		sum=0
		(i+4).step(j){|l|
			sum+=a[i+1][l-1]*a[l+1][j] if t.index(s[l,1])
		}
		a[i][j]=a[i+1][j]+sum
	}
}
p a[0][s.size-1]