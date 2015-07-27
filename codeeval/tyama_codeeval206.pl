#!/usr/bin/perl
use strict;
use warnings;
use feature qw(say);
use bigint;

sub comb{
	my($n,$k)=@_;
	return 0 if($k>$n);
	$k=$n-$k if($k>$n/2);
	my $r=1;
	for(my $i=0;$i<$k;$i++){
		$r=$r*($n-$i)/($i+1);
	}
	return $r;
}
while(<>){
	my $n=$_/2;
	my $s=0;
	for(my $k=0;$k<$n;$k++){$s+=(-1)**$k * comb(2*$n,$k) * comb(11*$n-1-10*$k,2*$n-1);}
	say $s;
}