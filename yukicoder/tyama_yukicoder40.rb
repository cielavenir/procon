#!/usr/bin/ruby

def checkio(exp,div)
	c=[]
	while div.size<=exp.size
		d=exp[-1]/div[-1]
		c.push(d)
		div.size.times{|i|exp[i+exp.size-div.size]-=div[i]*d}
		#raise if exp[-1]!=0
		exp.pop
	end
	exp.pop while exp.size>1&&exp[-1]==0
	p exp.size-1
	puts exp*' '
end

gets
checkio(gets.split.map(&:to_i),[0,-1,0,1])