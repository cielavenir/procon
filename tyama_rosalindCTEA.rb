#!/usr/bin/ruby
M=(1<<27)-1
seqs=[]
seq=''
gets
while gets
	if $_[0..0]=='>'
		seqs<<seq
		seq=''
	else
		seq+=$_.chomp
	end
end
seqs<<seq
s=seqs[0]
t=seqs[1]
m=[*0..t.length]
a=[1]*(t.length+1)
s.length.times{|i|
	t.length.downto(1){|j|
		m[j]+=1
		x=m[j-1]+(s[i,1]==t[j-1,1] ? 0 : 1)
		if m[j]>x
			m[j]=x
			a[j]=a[j-1]
		elsif m[j]==x
			a[j]=(a[j]+a[j-1])%M
		end
	}
	m[0]+=1
	1.step(t.length){|j|
		x=m[j-1]+1
		if m[j]>x
			m[j]=x
			a[j]=a[j-1]
		elsif m[j]==x
			a[j]=(a[j]+a[j-1])%M
		end
	}
}
p a.last