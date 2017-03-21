#!/usr/bin/ruby
n,k=gets.split.map(&:to_i)
s=gets.chomp.chars
k.times{
	if s[0]=='A'
		s[0]='B'
	else
		s=s[1..-1].map{|c|c=='A'?'B':'A'}+['A']
	end
}
puts s*''
