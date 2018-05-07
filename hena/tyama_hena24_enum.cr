#!/usr/bin/env crystal
#http://qiita.com/Nabetani/items/1c83005a854d2c6cbb69
#http://nabetani.sakura.ne.jp/hena/ord24eliseq/

def isqrt(n)
	return 0 if n<=0
	return 1 if n<4 # 1
	x,y=0,n
	while x!=y&&x+1!=y
		x,y=y,(n/y+y)/2
	end
	x
end
def icbrt(n)
	return -icbrt(n) if n<0
	return 0 if n==0
	return 1 if n<8 # 1,7
	x,y=0,n
	while x!=y&&x+1!=y
		x,y=y,(n/y/y+y*2)/3
	end
	x
end

def generate
	nxt=Channel(Int32).new
	i=1
	spawn{
		loop{
			nxt.send(i)
			i+=1
		}
	}
	nxt
end

def drop_prev(check,prev : Channel(Int32))
	a=prev.receive
	b=prev.receive
	nxt=Channel(Int32).new
	spawn{
		loop{
			nxt.send(a) if !check.call(b)
			a,b=b,prev.receive
		}
	}
	nxt
end

def drop_next(check,prev : Channel(Int32))
	a=prev.receive
	b=prev.receive
	nxt=Channel(Int32).new
	nxt.send(a)
	spawn{
		loop{
			nxt.send(b) if !check.call(a)
			a,b=b,prev.receive
		}
	}
	nxt
end

def drop_n(check,n : Int,prev : Channel(Int32))
	nxt=Channel(Int32).new
	i=0
	spawn{
		loop{
			i+=1
			a=prev.receive
			nxt.send(a) if !check.call(i,n)
		}
	}
	nxt
end

is_sq=->(n : Int32){isqrt(n)**2==n}
is_cb=->(n : Int32){icbrt(n)**3==n}
is_multiple=->(i : Int32,n : Int32){i%n==0}
is_le=->(i : Int32,n : Int32){i<=n}

f={
	'S' => ->(enm : Channel(Int32)){drop_next(is_sq,enm)},
	's' => ->(enm : Channel(Int32)){drop_prev(is_sq,enm)},
	'C' => ->(enm : Channel(Int32)){drop_next(is_cb,enm)},
	'c' => ->(enm : Channel(Int32)){drop_prev(is_cb,enm)},
	'h' => ->(enm : Channel(Int32)){drop_n(is_le,100,enm)},
}
(2..9).each{|e|f[e.to_s[0]]=->(enm : Channel(Int32)){drop_n(is_multiple,e,enm)}}

while s=gets
	#cS => f['S'].call(f['c'].call(generate))
	enm=s.chomp.chars.reduce(generate){|s,e|f[e].call(s)}
	10.times{|i|
		print ',' if i>0
		print enm.receive
	}
	STDOUT.flush
end
