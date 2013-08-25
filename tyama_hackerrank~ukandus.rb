#!/usr/bin/ruby
a=gets.to_i.times.map{gets.chomp.split}.reduce(:+)
gets.to_i.times{
	s=gets.chomp[0..-3]
	p a.count{|e|e==s+'se'}+a.count{|e|e==s+'ze'}
}