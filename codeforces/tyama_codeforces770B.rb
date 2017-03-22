#!/usr/bin/ruby
n=gets.chomp
p [n,*(1...n.size).map{|i|
	(n[0,i].to_i-1).to_s+'9'*(n.size-i)
}].max_by{|e|[e.chars.map(&:to_i).reduce(:+),e.to_i]}.to_i
