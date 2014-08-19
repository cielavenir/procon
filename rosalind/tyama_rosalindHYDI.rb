#!/usr/bin/ruby
#draft: http://rosalind.info/problems/suggested/22/
kyle={}
DATA.each{|e|
	a=e.split
	kyle[a[0]]=a[1].to_f
}
s=gets.chomp
l,k=gets.split
l=l.to_i;k=k.to_f
s.chars.each_cons(l){|e|puts e*'' if e.map{|f|kyle[f]}.reduce(:+)/l+1e-9>k}
__END__
A 1.8
C 2.5
D -3.5
E -3.5
F 2.8
G -0.4
H -3.2
I 4.5
K -3.9
L 3.8
M 1.9
N -3.5
P -1.6
Q -3.5
R -4.5
S -0.8
T -0.7
V 4.2
W -0.9
Y -1.3