#!/usr/bin/ruby
a=gets.to_i.times.map{gets.chomp.split}.reduce(:+)
gets.to_i.times{
	s=gets.chomp
	p a.count{|e|e==s}+a.count{|e|e==s.gsub('our','or')}
}