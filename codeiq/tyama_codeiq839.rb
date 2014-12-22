#!/usr/bin/ruby
module Spacetalky
	def self.encode(s)
		return '?' if s.empty? || s!=s.downcase
		r=''
		s.each_char.chunk{|e|e}.each{|e|
			n=e[1].size
			while n>26
				r+=e[0]+122.chr
				n-=26
			end
			r+=e[0]+(96+n).chr
		}
		r
	end
	def self.decode(s)
		return 'X' if s.size%2==1
		s.scan(/../).map{|e|e[0]*(e[1].ord-96)}*''
	end
end
if __FILE__==$0
	puts $<.map{|e|
		e.chomp!
		decode=Spacetalky.decode(e)
		decode='X' if decode!='X'&&Spacetalky.encode(decode)!=e
		decode+':'+e
	}
	puts DATA.read
end
__END__
ENV:Ruby
POINT:RLE
例えばfooはfが1個にoが2個だからfaobにエンコードされます。
26を越えた分は単純に分割されます。例えば
aaaaaaaaaaaaaaaaaaaaaaaaaaa
はazaa。
このため奇数長の文字列を生成することはできません。

また、デコードしてエンコードした結果が異なる場合もあります。
例えばexerciseをデコードすると
eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeecccccccccsssss
になりますが、これをエンコードすると
ezepciseになり、一致しません。
※最初はこれを考えずにゴルフしてしまい、危うくはまるところでした。
やはり中継基地2をさっさと修理したほうが良さそうです。

ただし、squeezedに限っては、
sssssssssssssssssuuuuueeeeeeeeeeeeeeeeeeeeeeeeeeeeee
のようにeが連続してはいますが、「ezed」と26+4に分割されているので正しくエンコードできます。