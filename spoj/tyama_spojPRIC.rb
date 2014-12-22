#!/usr/bin/ruby
require 'prime'
n=1
2000.times{
	$> << (n.prime? ? 1 : 0)
	n=(n+1234567890)&0x7fffffff
}