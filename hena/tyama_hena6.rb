#!/usr/bin/env ruby
#http://qiita.com/Nabetani/items/5e1c944541f09f0f9711
#http://nabetani.sakura.ne.jp/hena/ord6kinship/
STDOUT.sync=true
z=0
a={}
4.times{|i|
	(3**i).times{|j|
		a[z+=1]=[i,j]
	}
}
while gets
	n,m=$_.split('->').map{|e|a[e.to_i]}
	if n[0]==m[0]&&n[1]==m[1]
		puts 'me'
	elsif n[0]==m[0]&&n[1]/3==m[1]/3
		puts 'si'
	elsif n[0]==m[0]&&n[1]/3/3==m[1]/3/3
		puts 'co'
	elsif n[0]==m[0]+1&&n[1]/3==m[1]
		puts 'mo'
	elsif n[0]+1==m[0]&&n[1]==m[1]/3
		puts 'da'
	elsif n[0]==m[0]+1&&n[1]/3/3==m[1]/3
		puts 'au'
	elsif n[0]+1==m[0]&&n[1]/3==m[1]/3/3
		puts 'ni'
	else
		puts '-'
	end
end