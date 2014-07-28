#!/usr/bin/ruby
def zeller(_y,m,d)
	m+=1
	if m<4 then _y-=1;m+=12 end
	y=_y/100;z=_y%100
	(5*y+z+y/4+z/4+13*m/5+d-1)%7
end
gets.to_i.times{
	y1,m1,d1=gets.split.map(&:to_i)
	y2,m2,d2=gets.split.map(&:to_i)
	m1+=1 if d1>1
	r=0
	if y1<y2
		r=m1.step(12).count{|m|zeller(y1,m,1)==0}
		(y1+1).step(y2-1){|y|r+=1.step(12).count{|m|zeller(y,m,1)==0}}
		r+=1.step(m2).count{|m|zeller(y2,m,1)==0}
	else
		r=m1.step(m2).count{|m|zeller(y1,m,1)==0}
	end
	p r
}
__END__
1
1901 1 1
2000 1 1