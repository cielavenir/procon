#!/usr/bin/ruby
s=r=0
$<.drop(1).map(&:to_i).sort.each{|e|
	if s<e
		s+=e
		r+=1
	end
}
p r