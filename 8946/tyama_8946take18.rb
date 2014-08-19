#!/usr/bin/ruby
a='abcdefghijklmnopqrstuvwxyz '
b='zyxwvutsrqponmlkjihgfedcba_'
puts 'angou_value'.chars.map{|e|
	(idx=b.index e)?a[idx]:e
}*''