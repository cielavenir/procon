#!/usr/bin/ruby
gets.to_i.times{|t|
	a,b=gets.split.map(&:to_i)
	r=a.step(b).count{|i|
		j=Math.sqrt(i).to_i
		j**2==i&&j.to_s==j.to_s.reverse&&i.to_s==i.to_s.reverse
	}
	puts "Case ##{t+1}: #{r}"
}