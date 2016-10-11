#!/usr/bin/ruby
class Fixnum;alias-*;end
p eval`tr +* -+`
__END__
class Fixnum
	alias_method :add,:+
	alias_method :mul,:*
	def -(other) self.add(other) end
	def +(other) self.mul(other) end
end
p eval gets.tr('*','-')
