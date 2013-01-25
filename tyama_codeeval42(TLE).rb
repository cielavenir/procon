#!/usr/bin/ruby
#TLE: submit "ruby tyama_codeeval42.rb tyama_codeeval42.in" result as PHP.
def dfs(s,d,l)
	if d==l
		r=eval(s.tr(' ','').gsub(/^0([1-9]+)/,'\1').gsub(/([+-])0([1-9]+)/,'\1\2')).abs
		[2,3,5,7].any?{|e|r%e==0}?1:0
	else
		r=0
		'+- '.chars{|e|
			s[d*2+1,1]=e
			r+=dfs(s,d+1,l)
		}
		r
	end
end
while gets
	s=$_.chomp
	l=s.size-1
	s=s.split('')*' '
	p dfs(s,0,l)
end