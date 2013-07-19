#!/usr/bin/ruby
raise "Ruby 1.9+ is required" if RUBY_VERSION<'1.9'
def zip(a)
	a.shift.zip(*a)
end
def zip_string(a) zip(a.map{|e|e.split('')}).map(&:join) end
#Stage1
a=[
	[0x1b,0x24,0x42,0x25,0x6d,0x21,0x3c,0x25,0x5e,0x3b,0x7a,0x1b,0x28,0x42].map(&:chr)*'',
	[0x1b,0x24,0x42,0x24,0x37,0x21,0x21,0x22,0x2a,0x21,0x21,0x1b,0x28,0x42,0x73,0x68,0x69].map(&:chr)*''
]
puts a.join("\n").encode(Encoding.default_external,'ISO-2022-JP') #shi
pass=['10 10 10 10 10'.split,'01 10 00 01 11'.split,'10 01 00 00 01'.split]
#pass.map!(&:reverse)
pass=pass.flatten.map{|e|'%02b'%e.to_i(2)}
pass=pass.each_slice(3).map{|e|e.join}*' '
puts pass