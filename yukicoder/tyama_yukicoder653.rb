#!/usr/bin/ruby
s=gets.chomp.chars.map(&:to_i)
if [0,6,7].include?(s[-1])
	puts :No
	exit
end
f=2
(s.size-1).downto(0){|i|
	if f==2&&[2,3,4].include?(s[i])
		if i==0
			puts :No
			exit
		end
		s[i-1]-=1
	elsif f>=1&&[0,6,7].include?(s[i])
		f=1
		f=0 if s[i]==0
	elsif f<=1&&0==s[i]
	else
		puts :No
		exit
	end
}
puts :Yes
