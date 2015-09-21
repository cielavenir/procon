#!/usr/bin/ruby
def perform(s)
	s.sub!(/OO/,'o') while s.sub!(/oo/,'O')
	s
end
 
s=gets.chomp
until (a=s.scan(/o{3,}kayama/)).empty?
	am=a.max_by(&:size)
	ami=s.index(am)
	ams=ami+am.size
	s=s[0,ami]+perform(am)+s[ams..-1]
end
puts s