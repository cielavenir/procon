#!/usr/bin/ruby
a=$<.map{|e|e.split('=').map{|f|f.strip.split}}
h={};g={}
a.each{|e|
	e[0].each{|e0|h[e0]=1}
	e[1].each{|e0|g[e0]=1}
}
id=h.keys
names=g.keys
answer=Hash.new{|h,k|h[k]=[]}
id.each{|e|
	name=names
	a.each{|f|
		if f[0].index(e)
			name&=f[1]
		end
	}
	#この時点で、eの行にnameは必ず存在する。
	#しかし、nameの行にeが存在するとは限らないので、この条件を利用してnameを絞り込む。
	name.select!{|g|
		a.none?{|f|f[1].index(g) && !f[0].index(e)}
	}
	answer[name.sort]<<e
}
puts answer.keys.sort.map{|e|answer[e]*' '+' = '+e* ' '}

__END__
入力中に存在する全IDに対し、入力から当該IDが存在する行を抜き出し、そのすべての行に書かれているnameを調べる。
次いで、入力から当該nameが存在する行を抜き出し、そのすべての行に当該IDが書かれていることを確かめる。
計算量はO(総ID数*行数)となる。