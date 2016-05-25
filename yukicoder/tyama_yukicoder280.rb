#!/usr/bin/ruby
#gets;a=gets.split;$><<a[-1]+?/+a[0]
#gets;$><<gets.split.rotate[-2,2]*?/
a=`dd`.split;$><<a[-1]+?/+a[1]
__END__
N=gets.to_i
a=gets.split.map &:to_i
b=[1]
1.step(N-1){|i|b[i]=Rational(b[i-1]*a[i-1],a[i])}
puts 1/b[N-1]

sed 1d|perl -ape'$_=$F[-1]."/".$F[0]'