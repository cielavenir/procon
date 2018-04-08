#!/usr/bin/ruby
def calc(s)
	r=0
	c=1
	s.each_char{|k|
		if k=='S'
			r+=c
		elsif k=='C'
			c*=2
		end
	}
	r
end
gets.to_i.times{|t|
	d,s=gets.split
	d=d.to_i
	print 'Case #%d: '%(t+1)
	if s.count('S')>d
		puts 'IMPOSSIBLE'
		next
	end
	s.sub!(/C+$/,'')
	r=0
	while calc(s)>d
		idx=s.rindex('C')
		s[idx],s[idx+1]=s[idx+1],s[idx]
		s.sub!(/C+$/,'')
		r+=1
	end
	p r
}
