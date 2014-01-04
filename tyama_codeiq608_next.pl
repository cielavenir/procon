#!/usr/bin/perl
use strict;
use warnings;
sub my_reverse{
	my($a,$start,$size)=@_;
	my $end=$start+$size-1;
	for(;$start<$end;$start++){
		my $z=$a->[$start];$a->[$start]=$a->[$end];$a->[$end]=$z;
		$end--;
	}
}
sub next_permutation{
	my($a,$_n)=@_;
	my $siz=scalar(@$a);
	my $n=$_n || $siz;
	if($n<0||$siz<$n){return 0;}
	my $i=0;
	my_reverse($a,$n,$siz-$n);
	for($i=$siz-2;$i>=0;$i--){if($a->[$i]<$a->[$i+1]){last;}}
	if($i<0){
		my_reverse($a,0,$siz);
		return 0;
	}
	my $k=$i;
	for($i=$siz-1;$i>=$k+1;$i--){if($a->[$k]<$a->[$i]){last;}}
	my $l=$i;
	my $z=$a->[$k];$a->[$k]=$a->[$l];$a->[$l]=$z;
	my_reverse($a,$k+1,$siz-($k+1));
	return 1;
}

my $N=6;
my @e0;
my @f0;
my $i;
my $r=0;
for($i=0;$i<$N;$i++){
	$e0[$i]=$f0[$i]=0;
	$e0[$N+$i]=$f0[$N+$i]=1;
}
my @e=(0);
my @f=(0);
do{
	for($i=0;$i<$N*2;$i++){$e[$i+1]=$e[$i]+$e0[$i];}
	do{
		for($i=0;$i<$N*2;$i++){
			$f[$i+1]=$f[$i]+$f0[$i];
			if($e[$i]==$f[$i]&&$e[$i+1]==$f[$i+1]){last;}
		}
		if($i==$N*2){$r++;}
	}while(next_permutation(\@f0));
}while(next_permutation(\@e0));
print $r."\n";