#!/usr/bin/env ruby
#http://qiita.com/Nabetani/items/1c83005a854d2c6cbb69
#http://nabetani.sakura.ne.jp/hena/ord24eliseq/

=begin
if RUBY_VERSION<'1.9'
	module Math
		def self.cbrt(n)
			n**(1-2.0/3)
		end
	end
end
=end

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
		return -self.icbrt if self<0
		return 0 if self==0
		return 1 if self<8 # 1,7
		x,y=0,self
		while x!=y&&x+1!=y
			x,y=y,(self/y/y+y*2)/3
		end
		x
	end
end

=begin
def generate
	return to_enum(:generate) if !block_given?
	i=1
	loop{
		yield i
		i+=1
	}
end
=end

def drop_prev(check,prev)
	return to_enum(:drop_prev,check,prev) if !block_given?
	a=prev.next
	b=prev.next
	loop{
		yield a if !check[b]
		a,b=b,prev.next
	}
end
def drop_next(check,prev)
	return to_enum(:drop_next,check,prev) if !block_given?
	a=prev.next
	b=prev.next
	yield a
	loop{
		yield b if !check[a]
		a,b=b,prev.next
	}
end
def drop_n(check,n,prev)
	return to_enum(:drop_n,check,n,prev) if !block_given?
	i=0
	loop{
		i+=1
		a=prev.next
		yield a if !check[i,n]
	}
end

is_sq=lambda{|n|n.isqrt**2==n}
is_cb=lambda{|n|n.icbrt**3==n}
is_multiple=lambda{|i,n|i%n==0}
is_le=lambda{|i,n|i<=n}

if RUBY_VERSION<'1.9'
	f={
		'S'=>lambda{|enum|drop_next(is_sq,enum)},
		's'=>lambda{|enum|drop_prev(is_sq,enum)},
		'C'=>lambda{|enum|drop_next(is_cb,enum)},
		'c'=>lambda{|enum|drop_prev(is_cb,enum)},
		'h'=>lambda{|enum|drop_n(is_le,100,enum)},
	}
	(2..9).each{|e|f[e.to_s]=lambda{|enum|drop_n(is_multiple,e,enum)}}
else
	f={
		'S'=>Kernel.method(:drop_next).to_proc.curry[is_sq],
		's'=>Kernel.method(:drop_prev).to_proc.curry[is_sq],
		'C'=>Kernel.method(:drop_next).to_proc.curry[is_cb],
		'c'=>Kernel.method(:drop_prev).to_proc.curry[is_cb],
		'h'=>Kernel.method(:drop_n).to_proc.curry[is_le,100],
	}
	(2..9).each{|e|f[e.to_s]=Kernel.method(:drop_n).to_proc.curry[is_multiple,e]}
end

if $0==__FILE__
	STDOUT.sync=true
	while gets
		#cS => f['S'].call(f['c'].call(1.upto(1/0.0)))
		puts $_.chomp.chars.reduce(1.upto(1/0.0)){|s,e|f[e][s]}.take(10)*','

		#enum=generate
		#$_.chomp.chars.each{|e|enum=f[e][enum]}
		#puts enum.take(10)*','
	end
end
