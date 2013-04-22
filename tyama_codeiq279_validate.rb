#!/usr/bin/ruby
CODES=['r','g','b']
h={}
DATA.each{|e|
	l=e.split
	h[l[0]]=l[1].to_i
}
a=26.times.map{gets.chomp.split':'}
0.step(a.size-1){|i|
	raise "format error #{a[i][1]}" if a[i][1].chars.any?{|e|!CODES.find{|f|f==e}}
}
0.step(a.size-1){|i|
	0.step(a.size-1){|j|
		next if i==j
		raise "duplicate #{a[i][1]} #{a[j][1]}" if a[i][1].start_with? a[j][1]
	}
}
p 0.step(a.size-1).map{|i|h[a[i][0]]*a[i][1].size}.reduce(:+)
__END__
E 1194
T 1001
A 805
I 694
O 662
H 653
N 581
S 572
R 460
D 410
L 398
U 295
W 246
Y 226
C 209
M 201
G 199
K 123
F 121
P 110
B 107
V 74
J 11
Q 9
Z 5
X 5