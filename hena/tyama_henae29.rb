#!/usr/bin/ruby
#http://nabetani.sakura.ne.jp/hena/orde29unes/
#https://qiita.com/Nabetani/items/f2db9b916c0a301b744f

def solve(s)
	r=[]
	k="".dup
	escape=nil
	i=0
	while i<s.size
		if s[i]=="'"
			if !escape
				escape="'"
			elsif escape=="'"
				escape=nil
			else
				k<<"'"
			end
		elsif s[i]=='"'
			if !escape
				escape='"'
			elsif escape=='"'
				escape=nil
			else
				k<<'"'
			end
		elsif s[i]=="/"
			if escape
				k<<"/"
			elsif s[i+1]=="/"
				i+=1
				k<<"/"
			else
				r<<k
				k="".dup
			end
		else
			k<<s[i]
		end
		i+=1
	end
	r<<k
	if escape || r.any?(&:empty?)
		"-"
	else
		r*","
	end
end

while gets
	puts solve($_.chomp)
	STDOUT.flush
end
