#!/usr/bin/ruby
#http://nabetani.sakura.ne.jp/kanagawa.rb/evalex/

begin
	require 'iseq'
rescue LoadError
	require 'fiddle'

	class RubyVM
		class InstructionSequence
			addr = Fiddle.dlopen(nil)['rb_iseq_load']
			fn   = Fiddle::Function.new(addr, [Fiddle::TYPE_VOIDP] * 3, Fiddle::TYPE_VOIDP)
			define_singleton_method(:load) do |dat, par=nil, opt=nil|
				fn.call(Fiddle.dlwrap(dat), par, opt).to_value
			end
		end
	end
end

while gets
	bytecode=RubyVM::InstructionSequence.compile($_.tr('*+&|','|&+*')).to_a
	bytecode[13].map!{|e|
		if e[1].is_a?(Hash)&&e[1].has_key?(:mid)
			e[1][:mid]=e[1][:mid].to_s.tr('*+&|','|&+*').to_sym
			e[0]={:* => :opt_mult,:+ => :opt_plus,:& => :opt_send_simple,:| => :opt_send_simple}[e[1][:mid]]
		end
		e
	}
	p RubyVM::InstructionSequence.load(bytecode).eval
end