#!/usr/bin/ruby
n=gets.to_i
*S,T=$<.map &:chomp
l=r=0
S.each{|e|
	l+=1 if e.gsub('?','a')<=T
	r+=1 if e.gsub('?','z')<T
}
puts [*r+1..l+1]*' '
