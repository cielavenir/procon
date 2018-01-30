#!/usr/bin/ruby
s=gets
puts %w(1 4).select{|q|
	a=s.tr(??,q).split.map &:to_i
	a.uniq==a && a.minmax.include?(a[1])
}*''
