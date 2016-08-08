#!/usr/bin/ruby
s=0
gets;$/=' '
$<.each{|e|
	s=(s+e.to_i-1)%2
	p 2-s
}