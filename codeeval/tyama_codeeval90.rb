#!/usr/bin/ruby
x=[];y=[]
n=0
while DATA.gets
	$_=~/\((.+)\)/
	x[n],y[n]=$1.split(',').map{|e|e.to_f*Math::PI/180}
	n+=1
end
m=Array.new(x.size){Array.new(x.size)}
x.size.times{|i|
	(i+1).step(x.size-1){|j|
		#m[i][j]=m[j][i]=Math::hypot(x[i]-x[j],y[i]-y[j])
		m[i][j]=m[j][i]=Math::acos(Math::sin(x[i])*Math::sin(x[j])+Math::cos(x[i])*Math::cos(x[j])*Math::cos(y[i]-y[j]))
	}
}
d=1e8;z=[]
[*1..n-1].permutation{|a|
	b=[0]+a
	c=0
	(b.size-1).times{|i|
		c=c+m[b[i]][b[i+1]]
	}
	if c<d then d=c;z=b end
}
z.each{|e|p e+1}
=begin
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
=end
__END__
1 | CodeEval 1355 Market St, SF (37.7768016, -122.4169151)
2 | Yelp 706 Mission St, SF (37.7860105, -122.4025377)
3 | Square 110 5th St, SF (37.7821494, -122.4058960)
4 | Airbnb 99 Rhode Island St, SF (37.7689269, -122.4029053)
5 | Dropbox 185 Berry St, SF (37.7768800, -122.3911496)
6 | Zynga 699 8th St, SF (37.7706628, -122.4040139)
7 | Mashery 717 Market St, SF (37.7870361, -122.4039444)
8 | Flurry 3060 3rd St, SF (37.7507903, -122.3877184)
9 | New Relic 188 Spear St, SF (37.7914417, -122.3927229)
10 | Glassdoor 1 Harbor Drive, Sausalito (37.8672841, -122.5010216)