#!/usr/bin/ruby
n=0
gets.chomp.bytes{|b|
	n=(n+1..n+26).find{|i|i%26==b-65}
}
p n/26
