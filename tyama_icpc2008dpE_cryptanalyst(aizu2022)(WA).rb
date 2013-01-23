#!/usr/bin/ruby
while(n=gets.to_i)>0
s=n.times.map{gets.chomp}.sort
while s.size>1
    k=[0,-1,-1]
	s.length.times{|i|
		s.length.times{|j|
			if i!=j
				n=[s[i].size,s[j].size].min
				n-=1 while n>0&&s[i][-n..-1]!=s[j][0,n]
				k=[n,i,j] if n>k[0]
			end
		}
	}
	if k[0]==0 then
		s=[s.sort.join];break
	end
	s.push(s[k[1]]+s[k[2]][k[0]..-1])
	s[k[1]]=s[k[2]]=nil
	s=s.select{|e|e}
end
puts s[0]
end