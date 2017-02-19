#!/usr/bin/ruby
n,k,*d=`dd`.split.map(&:to_i)
q=0
n.times{|i|
	if d[i]>=0
		d[i],c=-1,d[i]-1
		q+=0
		while c!=i
			d[c],c=-1,d[c]-1
			q+=1
		end
	end
}
puts q<=k&&q%2==k%2?:YES: :NO
