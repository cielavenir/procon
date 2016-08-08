#!/usr/bin/ruby
gets.to_i.times{|i|
	print "Case ##{i+1}: "
	n=gets.to_i
	a=4.times.map{gets}[n-1].split.map(&:to_i)
	n=gets.to_i
	a=a&4.times.map{gets}[n-1].split.map(&:to_i)
	if a.size==0
		puts 'Volunteer cheated!'
	elsif a.size==1
		p a[0]
	else
		puts 'Bad magician!'
	end
}