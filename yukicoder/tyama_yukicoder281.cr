#!/usr/bin/env crystal
def solve_short(d,a,b,c)
	begin
		r=0_i64
		if a==c
			c=[0,c-d].max
			r+=1
		end
		t=b-[a,c].min+1
		if t>0
			cnt=(t+d-1)//d
			r+=cnt
			b=[0,b-r*d].max
		end
		a==b || b==c ? -1 : r
	rescue DivisionByZeroError
		-1
	end
end
def solve_tall(d,a,b,c)
	begin
		r=0_i64
		t=a-b+1
		if t>0
			cnt=(t+d-1)//d
			r+=cnt
			a=[0,a-cnt*d].max
		end
		t=c-b+1
		if t>0
			cnt=(t+d-1)//d
			r+=cnt
			c=[0,c-cnt*d].max
		end
		if a==c
			c=[0,c-d].max
			r+=1
		end
		a==b || b==c || c==a ? -1 : r
	rescue DivisionByZeroError
		-1
	end
end
d,a,b,c=4.times.map{gets.not_nil!.to_i}.to_a
x=solve_short(d,a,b,c)
y=solve_tall(d,a,b,c)
p x>=0&&y>=0 ? [x,y].min : [x,y].max
