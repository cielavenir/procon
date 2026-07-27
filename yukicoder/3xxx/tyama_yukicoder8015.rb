#!/usr/bin/ruby
#cf: http://www.utpc.jp/2012/slides/Uinny.pdf

N=10

def calc(s)
	r=0
	b=1
	s.size.times{|i|
		r=(r+b*s[s.size-i-1].ord)%P
		b=(b*B)%P
	}
	r
end

B,P=$<.read.split.map(&:to_i)
alphabet=[*'a'..'z']
h={}
loop{
	x=N.times.map{alphabet.sample}.join
	v=calc(x)
	if h.has_key?(v)
		if h[v]!=x
			puts h[v]
			puts x
			break
		end
	else
		h[v]=x
	end
}