#!/usr/bin/ruby
gets.to_i.times{
	x,a,b,n=gets.split.map(&:to_i)
	k=163*60/x
	cnt=(60+x-1)/x
	ncnt=[cnt-n,0].max
	#cnt-=ncnt
	r=0
	k.times{|i|
		if i%cnt<cnt-ncnt
			r+=a
		else
			r+=b
		end
	}
	p r/100
}
#フレンド回復を待つべき場合を考えてなかった