#!/usr/bin/env ruby
#http://nabetani.sakura.ne.jp/hena/ordf04octsp/
#http://qiita.com/Nabetani/items/8ead5622e192d9655cf5
STDOUT.sync=true
while gets
	n=$_.to_i
	a=8.times.select{|i|n[i]==1}
	puts a.size.times.map{|i|
		b=(a[(i+1)%a.size]-a[i])%8
		r=(b==4 ? 2 : 3)
		#b+=1 if a[i]%2==1
		r+(b-1) #/2
	}.sort*''
end
