#!/usr/bin/ruby
=begin
require 'ffi'
module LibC
	extend FFI::Library
	ffi_lib FFI::Library::LIBC
	attach_function :puts, [:string], :int
	attach_function :scanf, [:string,:pointer], :int
	define_singleton_method(:scanlld){
		r=FFI::MemoryPointer.new(:char,8)
		scanf("%lld",r)
		r.read_int64
	}
end
=end

=begin
require 'fiddle'
require 'fiddle/import'
module C
	extend Fiddle::Importer
	if [/mswin/,/mingw/].any?{|e|e=~RUBY_PLATFORM}
		libc = Fiddle.dlopen('msvcrt')
	else
		libc = Fiddle.dlopen(nil)
	end
	lld_buf=struct(['long long value']).malloc
	scanf_addr = libc['scanf']
	scanlld_fn = Fiddle::Function.new(scanf_addr, [Fiddle::TYPE_VOIDP, Fiddle::TYPE_VOIDP], Fiddle::TYPE_INT)
	define_singleton_method(:scanlld){
		#r="\0"*8
		scanlld_fn.call("%lld",lld_buf)
		#r.unpack('q')[0]
		lld_buf.value
	}
	puts_addr = libc['puts']
	puts_fn = Fiddle::Function.new(puts_addr, [Fiddle::TYPE_VOIDP], Fiddle::TYPE_INT)
	define_singleton_method(:puts){|s|
		puts_fn.call(s)
	}
end
=end

#T=C.scanlld
T=gets.to_i
T.times{
	#a=C.scanlld
	#b=C.scanlld
	#c=C.scanlld
	a,b,c=gets.split.map(&:to_i)
	if a==0
		if b==0
			puts c!=0 ? "0" : "3"
		else
			puts "1 %.12f"%[-c*1.0/b]
		end
	else
		if a<0
			a = -a
			b = -b
			c = -c
		end
		d=b*b-4.0*a*c
		if d.abs<1e-9
			puts "1 %.12f"%[-b/2.0/a]
		elsif d<0
			puts "0"
		else
			# acknowledgement: http://tricky.contest.atcoder.jp/submissions/120839
			x=y=0.0
			if b>0
				x = (-b-Math.sqrt(d))/2/a
				y = c*1.0/a/x
			else
				y = (-b+Math.sqrt(d))/2/a
				x = c*1.0/a/y
			end
			puts "2 %.12f %.12f"%[x,y]
		end
	end
}
