#!/usr/bin/ruby
N=gets.to_i
r=0
A=[]
(2*N).times.map{|i|gets.split.map(&:to_i)+[i/N]}.sort.each{|x,y,c|
	if c==0
		A<<y
	else
		k=-1
		ki=-1
		A.each_with_index{|z,i|
			if k<z && z<y
				k=z
				ki=i
			end
		}
		if ki>=0
			A.delete_at(ki)
			r+=1
		end
	end
}
p r
