#!/usr/bin/ruby
require 'bigdecimal'
x=[];y=[]
n=0
while DATA.gets
	$_=~/\((.+)\)/
	x[n],y[n]=$1.split(',')
	x[n]=BigDecimal.new(x[n])
	y[n]=BigDecimal.new(y[n])
	n+=1
end
m=Array.new(x.size){Array.new(x.size)}
x.size.times{|i|
	(i+1).step(x.size-1){|j|
		m[i][j]=m[j][i]=((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j])).sqrt(10)
	}
}
d=BigDecimal('999');z=[]
[*1..n-1].permutation{|a|
	b=[0]+a
	c=BigDecimal.new('0')
	(b.size-1).times{|i|
		c=c+m[b[i]][b[i+1]]
	}
	if c<d then d=c;z=b end
}
z.each{|e|p e+1}
__END__
1 | Home 255 King St, San Francisco, CA 94107, United States (37.7760035, -122.39317110000002)
2 | Twitter 1355 Market St, San Francisco, CA 94103, United States (37.776246, -122.41792229999999)
3 | Square 110 5th St, San Francisco, CA 94103, United States (37.7821494, -122.40589599999998)
4 | Yelp 706 Mission St, San Francisco, CA, United States (37.7860105, -122.40253769999998)
5 | Airbnb 99 Rhode Island St, San Francisco, CA 94103, United States (37.7689269, -122.40290529999999)
6 | Eventbrite 651 Brannan St, San Francisco, CA 94107, United States (37.77522700000001, -122.399631)
7 | Dropbox 185 Berry St, San Francisco, CA 94107, United States (37.7766511, -122.3922604)
8 | Zynga 699 8th St, San Francisco, CA 94103, United States (37.7713265, -122.40271139999999)
9 | Pinterest 808 Brannan St, San Francisco, CA 94103, United States (37.772996, -122.40374199999997)
10 | Uber 405 Howard Street, San Francisco, CA 94105, United States (37.78853, -122.39514400000002)