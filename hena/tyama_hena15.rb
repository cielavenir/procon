#!/usr/bin/env ruby
#http://qiita.com/Nabetani/items/cba03c96d1ea55f6e861
#http://nabetani.sakura.ne.jp/hena/ord15elebubo/

STDOUT.sync=true
while gets
	s=''
	a=$_.chomp.split('/').map{|e|('%032b'%e.to_i(16)).chars.map{|f|f=='1'}}
	raise if a[0].size!=32||a[1].size!=32
	i=0
	while i<a[0].size
		if !a[0][i]&&!a[1][i]
			i+=1
		elsif a[0][i]&&a[1][i]
			if a[0][i+1]
				if a[0][i+2]
					s+='N'
					i+=3
				else
					s+='R'
					i+=2
				end
			elsif a[1][i+1]
				if a[1][i+2]
					s+='U'
					i+=3
				else
					s+='L'
					i+=2
				end
			end
		elsif a[0][i]
			if a[0][i+2]
				s+='T'
				i+=3
			else #if a[1][i+2]
				s+='Z'
				i+=3
			end
		else
			if a[0][i+2]
				s+='S'
				i+=3
			else
				s+='J'
				i+=2
			end
		end
	end
	puts s
end