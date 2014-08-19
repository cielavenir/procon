#!/usr/bin/ruby
gets;a=gets.split.map(&:to_i)
a.size.times{|i|a.size.times{|j|(j+1).step(a.size-1){|k|
	if a[i]==a[j]+a[k] then puts [i+1,j+1,k+1]*' ';exit end
}}}
p -1