#!/usr/bin/ruby
a=[{}]
while gets
	h=a[0]
	$_.chomp.chars{|e|
		until h[e]
			a<<{}
			h[e]=a.size-1
		end
		h=a[h[e]]
	}
end
a.length.times{|i|
	a[i].each{|k,v|puts "#{i+1} #{v+1} #{k}"}
}