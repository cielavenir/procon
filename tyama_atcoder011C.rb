#!/usr/bin/ruby
def diff1(t,s)
	r=0
	t.length.times{|i|
		r+=1 if t[i]!=s[i]
		return false if r>1
	}
	true
end
f,l=gets.chomp.split
a=gets.to_i.times.map{gets.chomp}
if f==l then p 0;puts f;puts l;exit end
h={f=>nil}
q=[[f,0]]
while !q.empty?
	x,y=q.shift
	if diff1(x,l) then q.push([l,y+1]);h[l]=x;break end
	a.each{|e|if h.has_key?(e)&&diff1(x,e) then q.push([e,y+1]);h[e]=x end}
end
if q.empty? then p -1;exit end
a=[l];x=l
while h[x]
	a<<h[x];x=h[x]
end
p a.size-2
puts a.reverse.join"\n"