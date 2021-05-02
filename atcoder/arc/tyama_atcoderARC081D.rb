#!/usr/bin/ruby
gets;s=3;gets.chomp.gsub(/(.)\1/,?.).chars.chunk{|c|c>?.}.map{|k,v|
	n=v.size-1;s*=k ?2**n: 2*3**n
};p s%(10**9+7)
