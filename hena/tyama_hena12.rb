#!/usr/bin/ruby
#cf: codeiq708
#面のマッピング
C='123456'
T=[[4,0,2,3,5,1],[2,1,5,0,4,3],[1,5,2,3,0,4],[3,1,0,5,4,2]]
D={'N'=>0,'E'=>1,'S'=>2,'W'=>3}

while gets
	r='1'
	a=[*0..5]
	$_.chomp.each_char.with_index{|c,i|
		a=T[D[c]].map{|e|a[e]}
		r<<C[a[0]]
	}
	puts r
end
