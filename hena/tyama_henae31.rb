#!/usr/bin/ruby
#http://nabetani.sakura.ne.jp/hena/orde31rotnum/
#https://qiita.com/Nabetani/items/d139d5ef70aa23c2d038

# can run on both Ruby and Crystal.

def chk(n,b)
	n,r=n.divmod b
	while n>0
		n,r0=n.divmod b
		if r0!=r && (r0+1)%b!=r
			return false
		end
		r=r0
	end
	true
end

while s=gets
	b_,x_,y_=s.chomp.split(",")
	b=b_.to_i
	x=x_.to_i(b)
	y=y_.to_i(b)
	p (x..y).count{|i|chk(i,b)}
	STDOUT.flush
end
