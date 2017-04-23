#!/usr/bin/ruby
#aizu0157
n=gets.to_i
a=n.times.map{gets.split.map(&:to_i).sort}.sort
d=[]
n.times{|i|
	d[i]=1
	i.times{|j|
		if (0..2).all?{|x|a[j][x]<a[i][x]}
			d[i]=[d[j]+1,d[i]].max
		end
	}
}
p d.max
