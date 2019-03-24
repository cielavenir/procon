#!/usr/bin/ruby
def encode(s)
	r=[]
	a=s.chars
	i=0
	while !a.empty?
		i+=1
		x=a.shift(i)
		if i%2==1
			r+=x
		else
			r=x+r
		end
	end
	r*''
end
def decode(s)
	r=[]
	o=[]
	a=s.chars
	t=i=0
	while t<a.size
		o<<i+=1
		t+=i
	end
	if t>a.size
		o[-1]-=t-a.size
	end
	(o.size-1).downto(0){|i|
		r=a.send(i%2==0 ? :pop : :shift,o[i])+r
	}
	r*''
end
n=gets.to_i
s=gets.chomp
if n>=0
	n.times{s=decode(s)}
else
	(-n).times{s=encode(s)}
end
puts s
