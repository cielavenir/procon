#!/usr/bin/ruby
gets.to_i.times{
	n=gets.to_i
	if n<3
		p -1
	else
		a=[1,2,3]
		4.step(n){
			a=[1]+[a[0]+a[1]]+a.each_cons(3).map{|x,y,z|x+y+z}+[a[-2]+a[-1]+a[-2]]
		}
		p a.each.with_index(1).find{|e,i|e%2==0}.last
	end
}