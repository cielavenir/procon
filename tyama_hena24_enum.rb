#!/usr/bin/env ruby
#http://qiita.com/Nabetani/items/1c83005a854d2c6cbb69
#http://nabetani.sakura.ne.jp/hena/ord24eliseq/
if RUBY_VERSION<'1.9'
	module Math
		def self.cbrt(n)
			n**(1.0/3)+1e-9
		end
	end
end
def generate
	return to_enum(:generate) if !block_given?
	i=1
	loop{
		yield i
		i+=1
	}
end
def drop_prev_square(prev)
	return to_enum(:drop_prev_square,prev) if !block_given?
	a=prev.next
	b=prev.next
	loop{
		yield a if Math.sqrt(b).to_i**2!=b
		a,b=b,prev.next
	}
end
def drop_next_square(prev)
	return to_enum(:drop_next_square,prev) if !block_given?
	a=prev.next
	b=prev.next
	yield a
	loop{
		yield b if Math.sqrt(a).to_i**2!=a
		a,b=b,prev.next
	}
end
def drop_prev_cubic(prev)
	return to_enum(:drop_prev_cubic,prev) if !block_given?
	a=prev.next
	b=prev.next
	loop{
		yield a if Math.cbrt(b).to_i**3!=b
		a,b=b,prev.next
	}
end
def drop_next_cubic(prev)
	return to_enum(:drop_next_cubic,prev) if !block_given?
	a=prev.next
	b=prev.next
	yield a
	loop{
		yield b if Math.cbrt(a).to_i**3!=a
		a,b=b,prev.next
	}
end
def drop_num(n,prev)
	return to_enum(:drop_num,n,prev) if !block_given?
	i=0
	loop{
		i+=1
		a=prev.next
		yield a if i%n!=0
	}
end
def drop_cnt(n,prev)
	return to_enum(:drop_cnt,n,prev) if !block_given?
	i=0
	loop{
		i+=1
		a=prev.next
		yield a if i>n
	}
end
f={
	'S'=>Kernel.method(:drop_next_square),
	's'=>Kernel.method(:drop_prev_square),
	'C'=>Kernel.method(:drop_next_cubic),
	'c'=>Kernel.method(:drop_prev_cubic),
	'h'=>RUBY_VERSION<'1.9' ?
		lambda{|enum|drop_cnt(100,enum)} :
		Kernel.method(:drop_cnt).to_proc.curry[100],
}
('2'..'9').each{|e|f[e]=RUBY_VERSION<'1.9' ?
	lambda{|enum|drop_num(e.to_i,enum)} :
	Kernel.method(:drop_num).to_proc.curry[e.to_i]
}

if $0==__FILE__
	STDOUT.sync=true
	while gets
		puts $_.chomp.chars.reduce(generate){|s,e|f[e][s]}.take(10)*','
=begin
		enum=generate
		$_.chomp.chars.each{|e|
			if e=='S'
				enum=drop_next_square(enum)
			elsif e=='s'
				enum=drop_prev_square(enum)
			elsif e=='C'
				enum=drop_next_cubic(enum)
			elsif e=='c'
				enum=drop_prev_cubic(enum)
			elsif e=='h'
				enum=drop_cnt(100,enum)
			else
				enum=drop_num(e.to_i,enum)
			end
		}
		puts enum.take(10)*','
=end
	end
end