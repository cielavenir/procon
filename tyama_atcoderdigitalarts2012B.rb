#!/usr/bin/ruby
s=gets.chomp
if s=='z'*20||s=='a'
	puts :NO
elsif s!=s.reverse
	puts s.reverse
elsif s=='a'*s.length
	puts (96+s.length).chr
elsif s=='z'*s.length
	puts 'z'*(s.length-1)+'ya'
elsif s.length==1
	puts (s.ord-1).chr+'a'
else
	x=0;y=0
	s.each_byte{|e|
		if e>97&&x==0 then print (e-1).chr;x=1
		elsif e<122&&y==0 then print (e+1).chr;y=1
		else print e.chr end
	};puts
end