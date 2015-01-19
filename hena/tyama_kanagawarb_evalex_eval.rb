#!/usr/bin/ruby
#http://nabetani.sakura.ne.jp/kanagawa.rb/evalex/

class Fixnum
	alias_method :or_real,:|
	alias_method :and_real,:&
	alias_method :plus_real,:+
	alias_method :mult_real,:*
	def |(other) self.mult_real(other) end
	def &(other) self.plus_real(other) end
	def +(other) self.and_real(other) end
	def *(other) self.or_real(other) end
end

while gets
	p eval($_.tr('*+&|','|&+*'))
end