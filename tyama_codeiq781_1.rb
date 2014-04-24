#!/usr/bin/ruby
a=DATA.flat_map{|e|e.split.map{|f|f.to_i(16)}}
a.size.times{|i|
	#' ','e','t','h'は尤も推測が楽
	a[i]=' ' if a[i]==0xcb
	a[i]='e' if a[i]==0x9c
	a[i]='t' if a[i]==0xba
	a[i]='h' if a[i]==0x4d

	#1文字ずつ解読
	a[i]='l' if a[i]==0x97
	a[i]='i' if a[i]==0xc2
	a[i]='n' if a[i]==0x24
	a[i]='w' if a[i]==0x07
	a[i]='o' if a[i]==0xda
	a[i]='s' if a[i]==0x0d
	a[i]='b' if a[i]==0xd3
	a[i]='a' if a[i]==0xf0
	a[i]='d' if a[i]==0x7d
	a[i]='c' if a[i]==0xcd
	a[i]='g' if a[i]==0x08
	a[i]='u' if a[i]==0x58
	a[i]='r' if a[i]==0x1c
	a[i]='p' if a[i]==0x3f
	a[i]='f' if a[i]==0xf9
	a[i]='y' if a[i]==0x2c
	a[i]='m' if a[i]==0xe4
	a[i]='k' if a[i]==0xa9
	a[i]='v' if a[i]==0x7f

	#以下は本文中からの解読は困難であったため検索が必要であった
	a[i]='"' if a[i]==0x78
	a[i]=',' if a[i]==0x21
	a[i]='-' if a[i]==0x25
	a[i]='.' if a[i]==0x50
	a[i]='\'' if a[i]==0xc5
	a[i]='Y' if a[i]==0xab
	a[i]='N' if a[i]==0x88
	a[i]='O' if a[i]==0xac
	a[i]='T' if a[i]==0x9d
	a[i]='I' if a[i]==0xb7
	a[i]='W' if a[i]==0xce
}
puts a*''

=begin
"You see, my dear Watson," -- he propped his test-tube in the rack, and began to lecture with the air of a professor addressing his class -- "it is not really difficult to construct a series of inferences, each dependent upon its predecessor and each simple in itself.  If, after doing so, one simply knocks out all the central inferences and presents one's audience with the starting-point and the conclusion, one may produce a startling, though possibly a meretricious, effect. Now, it was not really difficult, by an inspection of the groove between your left forefinger and thumb, to feel sure that you did NOT propose to invest your small capital in the gold fields."
=end

__END__
78 AB DA 58 CB 0D 9C 9C 21 CB E4 2C CB 7D 9C F0
1C CB CE F0 BA 0D DA 24 21 78 CB 25 25 CB 4D 9C
CB 3F 1C DA 3F 3F 9C 7D CB 4D C2 0D CB BA 9C 0D
BA 25 BA 58 D3 9C CB C2 24 CB BA 4D 9C CB 1C F0
CD A9 21 CB F0 24 7D CB D3 9C 08 F0 24 CB BA DA
CB 97 9C CD BA 58 1C 9C CB 07 C2 BA 4D CB BA 4D
9C CB F0 C2 1C CB DA F9 CB F0 CB 3F 1C DA F9 9C
0D 0D DA 1C CB F0 7D 7D 1C 9C 0D 0D C2 24 08 CB
4D C2 0D CB CD 97 F0 0D 0D CB 25 25 CB 78 C2 BA
CB C2 0D CB 24 DA BA CB 1C 9C F0 97 97 2C CB 7D
C2 F9 F9 C2 CD 58 97 BA CB BA DA CB CD DA 24 0D
BA 1C 58 CD BA CB F0 CB 0D 9C 1C C2 9C 0D CB DA
F9 CB C2 24 F9 9C 1C 9C 24 CD 9C 0D 21 CB 9C F0
CD 4D CB 7D 9C 3F 9C 24 7D 9C 24 BA CB 58 3F DA
24 CB C2 BA 0D CB 3F 1C 9C 7D 9C CD 9C 0D 0D DA
1C CB F0 24 7D CB 9C F0 CD 4D CB 0D C2 E4 3F 97
9C CB C2 24 CB C2 BA 0D 9C 97 F9 50 CB CB B7 F9
21 CB F0 F9 BA 9C 1C CB 7D DA C2 24 08 CB 0D DA
21 CB DA 24 9C CB 0D C2 E4 3F 97 2C CB A9 24 DA
CD A9 0D CB DA 58 BA CB F0 97 97 CB BA 4D 9C CB
CD 9C 24 BA 1C F0 97 CB C2 24 F9 9C 1C 9C 24 CD
9C 0D CB F0 24 7D CB 3F 1C 9C 0D 9C 24 BA 0D CB
DA 24 9C C5 0D CB F0 58 7D C2 9C 24 CD 9C CB 07
C2 BA 4D CB BA 4D 9C CB 0D BA F0 1C BA C2 24 08
25 3F DA C2 24 BA CB F0 24 7D CB BA 4D 9C CB CD
DA 24 CD 97 58 0D C2 DA 24 21 CB DA 24 9C CB E4
F0 2C CB 3F 1C DA 7D 58 CD 9C CB F0 CB 0D BA F0
1C BA 97 C2 24 08 21 CB BA 4D DA 58 08 4D CB 3F
DA 0D 0D C2 D3 97 2C CB F0 CB E4 9C 1C 9C BA 1C
C2 CD C2 DA 58 0D 21 CB 9C F9 F9 9C CD BA 50 CB
88 DA 07 21 CB C2 BA CB 07 F0 0D CB 24 DA BA CB
1C 9C F0 97 97 2C CB 7D C2 F9 F9 C2 CD 58 97 BA
21 CB D3 2C CB F0 24 CB C2 24 0D 3F 9C CD BA C2
DA 24 CB DA F9 CB BA 4D 9C CB 08 1C DA DA 7F 9C
CB D3 9C BA 07 9C 9C 24 CB 2C DA 58 1C CB 97 9C
F9 BA CB F9 DA 1C 9C F9 C2 24 08 9C 1C CB F0 24
7D CB BA 4D 58 E4 D3 21 CB BA DA CB F9 9C 9C 97
CB 0D 58 1C 9C CB BA 4D F0 BA CB 2C DA 58 CB 7D
C2 7D CB 88 AC 9D CB 3F 1C DA 3F DA 0D 9C CB BA
DA CB C2 24 7F 9C 0D BA CB 2C DA 58 1C CB 0D E4
F0 97 97 CB CD F0 3F C2 BA F0 97 CB C2 24 CB BA
4D 9C CB 08 DA 97 7D CB F9 C2 9C 97 7D 0D 50 78