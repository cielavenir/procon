#!/usr/bin/ruby
N=7
def calc(s)
	r=0
	b=1
	s.size.times{|i|
		r=(r+b*s[s.size-i-1].ord)%P
		b=(b*B)%P
	}
	r
end

B,P=gets.split.map(&:to_i)
alphabet=[*'a'..'z']
h={}
pairs={}
ok=0
loop{
	x=N.times.map{alphabet.sample}.join
	v=calc(x)
	if h.has_key?(v)
		if h[v]!=x
			if !pairs.has_key?(v)
				pairs[v]=[h[v],x]
				ok+=1
				break if ok==7
			end
		end
	else
		h[v]=x
	end
}
x=pairs.values
puts x.shift.product(*x).map(&:join)[0,100]