#!/usr/bin/env ruby
#18:16-18:26
#http://nabetani.sakura.ne.jp/hena/ordf03triom/
#http://qiita.com/Nabetani/items/becb4c4d309b4fe8ce0f
W=5
while gets
	h={}
	$_.chomp.bytes.each{|e|e-=97;h[[e/W,e%W]]=1}
	5.times{|y|5.times{|x|
		if h.has_key?([y,x]) #一番上の中で一番左
			if h.has_key?([y+1,x-1])&&h.has_key?([y+1,x])
				puts :J
			elsif h.has_key?([y+1,x])&&h.has_key?([y+1,x+1])
				puts :L
			elsif h.has_key?([y,x+1])&&h.has_key?([y+1,x+1])
				puts :T
			elsif h.has_key?([y,x+1])&&h.has_key?([y+1,x])
				puts :R
			elsif h.has_key?([y+1,x])&&h.has_key?([y+2,x])
				puts :I
			elsif h.has_key?([y,x+1])&&h.has_key?([y,x+2])
				puts :B
			else
				puts :-
			end
			break
		end
	}||break}
	STDOUT.flush
end
