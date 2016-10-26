#!/usr/bin/ruby
t={'\\'=>-1,'/'=>1,'_'=>0}
a=[0]
gets.chomp.each_char{|c|a<<(a.last+t[c])}
ma=a.max

#left=a.index(ma)
right=a.rindex(ma)
depth=nil
amount=0

water1=[]
0.upto(right-1){|i|
	if !depth
		if a[i]>a[i+1]
			depth=a[i]
		end
	end
	if depth
		amount+=(depth-a[i])+(depth-a[i+1])
	end
	if a[i+1]==depth
		depth=nil
		raise if amount%2>0
		water1<<amount/2
		amount=0
	end
}
raise if depth || amount>0

water2=[]
(a.size-1).downto(right+1){|i|
	if !depth
		if a[i]>a[i-1]
			depth=a[i]
		end
	end
	if depth
		amount+=(depth-a[i])+(depth-a[i-1])
	end
	if a[i-1]==depth
		depth=nil
		raise if amount%2>0
		water2<<amount/2
		amount=0
	end
}
raise if depth || amount>0

water=water1+water2.reverse
p water.reduce(0,:+)
puts [water.size,*water]*' '
