#!/usr/bin/ruby
k=gets.to_i
puts [200,300].map{|l|
	n=l/k
	r=0
	(1..n-1).each_cons(2){|e|
		#iとi+1について横幅を計算し小さい方
		x=e.map{|i|y=k*i;Math.sqrt((l/2)**2-(y-l/2)**2)/k*2}.min
		if n%2==0
			r+=x.to_i/2*2
		else
			r+=(x.to_i-1)/2*2+1
		end
	}
	r
}*' '
