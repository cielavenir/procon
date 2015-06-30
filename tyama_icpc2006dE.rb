#!/usr/bin/ruby
def dfs(s,_l,_r)
	r=''
	i=_l
	n=nil
	while i<_r
		if ('0'..'9').include?(s[i])
			if !n
				n=s[i].to_i
			else
				n=n*10+s[i].to_i
			end
			i+=1
		elsif s[i]=='('
			n=1 if !n
			cnt=1
			j=i+1
			while cnt>0
				if s[j]=='('
					cnt+=1
				elsif s[j]==')'
					cnt-=1
				end
				j+=1
			end
			r0=dfs(s,i+1,j-1)
			n.times{
				r+=r0
				return r if r.size>$n
			}
			n=nil
			i=j
		else
			n=1 if !n
			r+=s[i]*n
			n=nil
			i+=1
		end
	end
	r
end
i=0
loop{
	s,_=gets.split
	break if s=='0'
	$n=_.to_i
	r=dfs(s,0,s.size)
	puts r.size>$n ? r[$n] : '0'
}