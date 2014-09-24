#!/usr/bin/ruby
$<.map(&:to_i).each_slice(2){|a,b|
	exit if a==0&&b==0
	p a+b
}