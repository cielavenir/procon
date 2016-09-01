use feature qw(say);
use strict;
my($x,$y)=split(/ /,<>);
my $M=10**9+7;
my @I=(1,1);
my @F=(1,1);
my @R=(1,1);
for(my $i=2;$i<=$x;$i++){
	my $z=($M-($M/$i^0))*$I[$M%$i]%$M;
	$I[$i]=$z;
	$F[$i]=$i*$F[-1]%$M;
	$R[$i]=$z*$R[-1]%$M;
}
say $F[$x]*$R[$x-$y]%$M*$R[$y]%$M;