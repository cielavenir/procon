#!/usr/bin/ruby
h=Hash.new(0)
gets.chomp.each_char{|c|
	h[c]+=1
}
bk='z'
pair=''
center=''
flg=false
('a'..'z').each{|c|
	pair<<c*(h[c]/2)
	h[c]%=2
	if h[c]%2==1
		raise if flg
		bk=(bk.ord-1).chr while h[bk]%2==0
		if c==bk
			center=c
			flg=true
		else
			pair<<c
			h[c]=0
			h[bk]-=1
		end
	end
}
puts pair+center+pair.reverse