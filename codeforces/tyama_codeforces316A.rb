#!/usr/bin/ruby
h={}
f=10
x=0
gets.chomp.each_char.with_index{|c,i|
	if i==0&&!('0'..'9').include?(c)
		f=9
	end
	if c=='?'
		x+=1
	elsif ('A'..'J').include?(c)
		h[c]=1
	end
}
r=(11-h.size..10).reduce(1,:*)
if x>0
	r*=10
	x-=1
end
r=r*f/10
puts r.to_s+'0'*x