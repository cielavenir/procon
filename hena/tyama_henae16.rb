#!/usr/bin/env ruby
#http://nabetani.sakura.ne.jp/hena/orde16nontri/
#http://qiita.com/Nabetani/items/3525da55601bdf55316e

while gets
	s=($_.to_i+1).to_s(2)
	while idx=s.index('111')
		while idx>=0
			break if s[idx]=='0'
			idx-=1
		end
		if idx==-1
			s='1'+'0'*s.size
		else
			s[idx]='1'
			(idx+1...s.size).each{|i|s[i]='0'}
		end
	end
	while idx=s.index('000')
		s[idx+2]='1'
		(idx+3...s.size).each{|i|s[i]='0'}
	end
	p s.to_i(2)
	STDOUT.flush
end
