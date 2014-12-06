#!/usr/bin/ruby
def zeller(_y,m,d)
	m+=1
	if m<4 then _y-=1;m+=12 end
	y=_y/100;z=_y%100
	(5*y+z+y/4+z/4+13*m/5+d-1)%7
end
day=zeller(2014,7,23)
n=gets.to_i
if n<=2400
	p (2015..n).count{|i|zeller(i,7,23)==zeller(2014,7,23)}
else
	cycle=(2400...2800).count{|i|zeller(i,7,23)==day}
	p (2015...2400).count{|i|zeller(i,7,23)==day}+((n-2400)/400)*cycle+(n/400*400..n).count{|i|zeller(i,7,23)==day}
end