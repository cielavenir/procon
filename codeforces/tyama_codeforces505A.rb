#!/usr/bin/env ruby
s=gets.chomp
if s.size.even? && s==s.reverse
	puts s[0,s.size/2]+'a'+s[s.size/2..-1]
else
	(0..s.size).each{|i|
		a=s[0,i]+' '+s[i..-1]
		b=a.reverse
		if a.size.times.all?{|j|
			a[j,1]==' '||b[j,1]==' '||a[j]==b[j]
		}
			a.size.times{|j|
				print a[j,1]!=' ' ? a[j,1] : b[j,1]!=' ' ? b[j,1] : 'a'
			}
			puts
			exit
		end
	}
	puts :NA
end