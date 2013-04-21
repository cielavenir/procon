#!/usr/bin/ruby
a=[]
while gets
	if $_=~/height/
		$_=~/^\t([a-zA-Z]+)/
		name=$1
		pos=gets
		pos=~/([0-9\.]+),([0-9\.]+)/
		x=$1
		a<<[x.to_f,name]
	end
end
a.sort!
c=[]
b=[a[0][1]]
(a.size-1).times{|i|
	len = (a[i+1][0]-a[i][0]).to_i
	#puts len
	if len>50
		c<<b.sort
		b=[]
	end
	b<<a[i+1][1]
}
c<<b.sort
raise "len parameter is wrong for this graphviz version" if c.size!=2
puts c.max_by(&:size)*' '