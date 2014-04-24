#!/usr/bin/ruby
require 'digest/sha1'
=begin
def sha1(s,n)
	if true
		#s=s.chr
		#s=s.chr*20
		#s="\0"*19+s.chr
		s=s.chr+"\0"*19
		#p s
		n.times{s=Digest::SHA1.digest(s)}
	else
		#s=s.to_s(16)*20
		s=s.to_s
		(n-1).times{s=Digest::SHA1.hexdigest(s)}
		s=Digest::SHA1.digest(s)
	end
	s
end
=end

A=DATA.flat_map{|e|e.split.map{|f|f.to_i(16)}}
#puts A.map{|e|'0x%02x'%e}*','
#exit

#h=Hash.new(0)
#A.each{|e|h[e]+=1}
#p h
#p h.size
#exit
def test(enum)
	a=A.dup
	#p a
	if a.size.times{|i|
		n=enum.next
		#p [i,a[i],n]
		a[i]^=n
		#p [i,a[i].chr]
		break if a[i]<0x20 || 0x7f<=a[i]
	}
		puts a.map(&:chr)*''
		exit
	end
end

#1.step(10){|z|
256.times{|_s| # brute force all seeds
	#色々試してみたんですよ、ほんと。
=begin
	20.times{|_i|
		test(Enumerator.new{|y|
			cur=_s
			loop{
				y<<cur
				cur=sha1(cur,z)[_i].ord
			}
		})
	}
	test(Enumerator.new{|y|
		cur=_s
		loop{
			y<<cur
			cur=sha1(cur,z)[cur&0xf].ord
		}
	})
	test(Enumerator.new{|y|
		cur=_s
		loop{
			y<<cur
			cur=sha1(cur,z)[cur%20].ord
		}
	})
	test(Enumerator.new{|y|
		cur=_s
		loop{
			y<<cur
			cur=sha1(cur,z)[cur>>4].ord
		}
	})

	test(Enumerator.new{|y|
		cur=_s
		loop{
			y<<cur
			cur=sha1(cur,z).bytes.reduce(:+)%256
		}
	})
	test(Enumerator.new{|y|
		cur=_s
		loop{
			y<<cur
			cur=sha1(cur,z).bytes.reduce(:^)%256
		}
	})

	test(Enumerator.new{|y|
		cur=_s
		loop{
			y<<cur
			cur=sha1(cur,z).bytes.each_slice(2).map{|a,b|(a<<8)|b}.reduce(:+)%256
		}
	})
	test(Enumerator.new{|y|
		cur=_s
		loop{
			y<<cur
			cur=sha1(cur,z).bytes.each_slice(2).map{|a,b|(a<<8)|b}.reduce(:^)%256
		}
	})

	test(Enumerator.new{|y|
		cur=_s
		loop{
			y<<cur
			cur=sha1(cur,z).bytes.each_slice(2).map{|a,b|(b<<8)|a}.reduce(:+)%256
		}
	})
	test(Enumerator.new{|y|
		cur=_s
		loop{
			y<<cur
			cur=sha1(cur,z).bytes.each_slice(2).map{|a,b|(b<<8)|a}.reduce(:^)%256
		}
	})
=end

	#解説を見た後に
	test(Enumerator.new{|y|
		cur=_s # correct seed is 234.
		str=''
		loop{
			y<<cur
			str+=cur.chr #このような連結はわかるはずがない…
			cur=Digest::SHA1.digest(str)[-1].ord
		}
	})
	#まあ、最もなことを言えば、今回キーストリームの連結ではなくストレッチングの方に思考が行ってしまった時点で運が悪かったということになりましょうか。
}
#}
puts 'No luck...'

=begin
"If you use the code which I have explained," said Holmes,"you will find that it simply means 'Come here at once.' I was convinced that it was an invitation which he would not refuse, since he could never imagine that it could come from anyone but the lady. And so, my dear Watson, we have ended by turning the dancing men to good when they have so often been the agents of evil, and I think that I have fulfilled my promise of giving you something unusual for your notebook. Three-forty is our train, and I fancy we should be back in Baker Street for dinner."
=end

__END__
C8 EE A8 0F 80 FD 60 E9 00 3F C4 B0 10 2C E7 33
DC 82 1E 6B D3 5B BB FA 8A 48 C2 F0 97 7F A6 C0
9C 32 15 89 37 51 AA C9 D8 93 9D 86 DA 28 BB 58
A2 6D E2 7F 3A 3B A5 F1 A5 31 89 6C D8 B5 E6 15
BC A4 BC 59 93 CD 68 85 52 48 93 36 B1 F4 5E FA
D1 62 7C 4B C1 A2 E4 98 7F 17 D5 21 37 7F C5 A0
2C BE 67 4D DC 5A 0B 66 D9 D4 5B 09 58 2F 72 ED
4F 45 81 36 73 AB 18 DF 51 5C 1A D3 7F 2E EF B8
D8 C8 C0 8A 4C BA 87 23 01 44 46 E7 03 42 EF 44
EA 05 36 11 3C 03 67 24 A4 BC 53 EF 6E 2D C3 66
B9 CF 9C C2 55 04 9C F8 F4 99 B8 AF FF EA 16 7D
AA EC FF 7D E2 52 8B B7 65 EE 2C 69 07 1D D9 14
C5 5A 6B 5A BC EF 34 12 C4 0D 7D 4E AA DD 19 0A
2B 5F 8B CE 06 2D A0 6C 76 49 E2 62 AC 4B 04 46
FA E6 58 3E D0 7B 58 F0 8A 9E 67 1B 96 3C B3 93
94 66 8A 44 50 D5 4F F8 49 33 4E BA CA E1 95 24
92 43 85 FC A8 B1 66 6F 46 57 BD A5 B3 1E 1B 47
5B 95 EB E7 8C 41 25 DC 88 9D 66 72 36 6B C1 D8
E8 60 59 BA 1F BD 66 A7 3C A3 1D 08 DE CF EB 02
10 90 FD 9A F9 51 83 6C 22 79 6F 79 D7 98 52 43
DD 1E 66 AB E1 F0 E2 E4 85 0D 5F E5 B9 83 07 E0
84 9C B8 3A 60 1E 00 31 8B E9 7B 9B 6E 56 F0 84
81 A7 AE AE BE B2 56 0A C3 B8 DE B8 5C 8A 09 83
4C 9F 12 D3 DE C2 08 F2 79 CF 71 51 B3 E5 F0 D2
47 12 0E DF 98 B2 5C 02 E7 E3 4D B3 6B 20 91 0D
7C 0E E2 95 2E 7A 29 E2 7C C0 A8 9A B6 25 C1 FB
E5 EB A5 A0 F6 E2 E6 A0 70 4E E5 8F DE 1E 9C 33
29 2F DA 85 E0 9A C2 F6 6F 71 A9 84 E7 F9 61 29
50 3A 0A 65 C3 BD 91 CC 7E 52 69 84 12 27 6C 97
0C 9C FC 60 32 58 7D BD 2E 4F 5A 36 97 ED 34 5A
35 2F A8 ED DC A0 67 F0 FE 17 C9 E0 6E D6 D1 9D
58 C2 E0 81 6F C1 7F E9 38 5C EC 5A 30 08 00 CB
C3 65 2F A9 78 6D F5 C0 D1 34 8E 99 C8 52 85 E4
F7 06 FD E7 1B 14 9F 97 BD D9 97 29 18 8A 2A E4
76 AA 36 2D CE 4E E4 D0 84 69 65 22 0C 9B A4 42