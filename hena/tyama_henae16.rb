#!/usr/bin/env ruby
#http://nabetani.sakura.ne.jp/hena/orde16nontri/
#http://qiita.com/Nabetani/items/3525da55601bdf55316e

W=3
def q(n)
	n.times.map{|i|((i%W==W-1)?'1':'0')}*''
end

while gets
	s='0'+($_.to_i+1).to_s(2)
	if idx=s.index('0'+'1'*W)
		s=s[0...idx]+'1'+q(s.size-(idx+1))
	end
	if idx=s.index('0'*W)
		s=s[0...idx+W-1]+'1'+q(s.size-(idx+W))
	end
	p s.to_i(2)
	STDOUT.flush
end
