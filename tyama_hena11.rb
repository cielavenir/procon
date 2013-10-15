#!/usr/bin/env ruby
#http://qiita.com/Nabetani/items/93cde1a6b7561426a3ac
#http://nabetani.sakura.ne.jp/hena/ord11bitamida/
STDOUT.sync=true
while gets
	# d6-7b-e1-9e =>
	# [{0=>1, 1=>0, 3=>7, 7=>3}, {0=>3, 3=>0, 7=>8, 8=>7}, {1=>5, 5=>1, 6=>8, 8=>6}, {0=>2, 2=>0, 3=>4, 4=>3, 5=>7, 7=>5}]
	a=$_.split('-').map{|e|
		x={}
		l='%08b'%e.to_i(16)
		i=0
		while i<8
			if l[i,1]=='1'
				j=i+1
				while l[j,1]=='1' do j+=1 end
				x[i]=j;x[j]=i
				i=j
			else
				i+=1
			end
		end
		x
	}.reverse
	puts (0..8).map{|e|a.reduce(e){|s,f|s=f.has_key?(s)?f[s]:s}}*''
end