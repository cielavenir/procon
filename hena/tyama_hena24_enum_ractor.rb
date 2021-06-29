#!/usr/bin/env ruby
#http://qiita.com/Nabetani/items/1c83005a854d2c6cbb69
#http://nabetani.sakura.ne.jp/hena/ord24eliseq/

raise 'Ractor is not available (CRuby 3.0+ implements it). There is also non_ractor version.' if !defined?(Ractor)

class Integer
	def isqrt
		return 0 if self<=0
		return 1 if self<4 # 1
		x,y=0,self
		while x!=y&&x+1!=y
			x,y=y,(self/y+y)/2
		end
		x
	end
	def icbrt
		return -(-self).icbrt if self<0
		return 0 if self==0
		return 1 if self<8 # 1,7
		x,y=0,self
		while x!=y&&x+1!=y
			x,y=y,(self/y/y+y*2)/3
		end
		x
	end
end

def generate
	Ractor.new{
		i=1
		loop{
			Ractor.yield i
			i+=1
		}
	}
end

def drop_prev(check,prev)
	Ractor.new(check,prev){|check,prev|
		a=nil
		b=prev.take
		loop{
			a,b=b,prev.take
			Ractor.yield a if !check.(b)
		}
	}
end
def drop_next(check,prev)
	Ractor.new(check,prev){|check,prev|
		first=true
		a=nil
		b=nil
		loop{
			a,b=b,prev.take
			(first=false;Ractor.yield b) if (first || !check.(a))
		}
	}
end
def drop_n(check,n,prev)
	Ractor.new(check,n,prev){|check,n,prev|
		i=0
		loop{
			i+=1
			a=prev.take
			Ractor.yield a if !check.(i,n)
		}
	}
end

is_sq = Ractor.make_shareable ->n{n.isqrt**2==n}
is_cb = Ractor.make_shareable ->n{n.icbrt**3==n}
is_multiple = Ractor.make_shareable ->i,n{i%n==0}
is_le = Ractor.make_shareable ->i,n{i<=n}

f={
	'S'=>Kernel.method(:drop_next).to_proc.curry.(is_sq),
	's'=>Kernel.method(:drop_prev).to_proc.curry.(is_sq),
	'C'=>Kernel.method(:drop_next).to_proc.curry.(is_cb),
	'c'=>Kernel.method(:drop_prev).to_proc.curry.(is_cb),
	'h'=>Kernel.method(:drop_n).to_proc.curry.(is_le,100),
}
(2..9).each{|e|f[e.to_s]=Kernel.method(:drop_n).to_proc.curry.(is_multiple,e)}

if $0==__FILE__
	STDOUT.sync=true
	while gets
		x = $_.chomp.chars.reduce(generate){|s,e|f[e].(s)}
		puts 10.times.map{x.take}*','
	end
end
