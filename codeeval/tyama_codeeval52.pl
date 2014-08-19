#!/usr/bin/perl
use strict;
use warnings;
my @A=(
	'',
	'One','Two','Three','Four','Five','Six','Seven','Eight','Nine','Ten',
	'Eleven','Twelve','Thirteen','Fourteen','Fifteen','Sixteen','Seventeen','Eighteen','Nineteen'
);
my @B=('Twenty','Thirty','Forty','Fifty','Sixty','Seventy','Eighty','Ninety');
sub txt{
	my $x=shift;
	my $s='';
	$s.=$A[$x/100^0].'Hundred' if(($x/100^0)>0);
	return $s.$A[$x%100] if($x%100<20);
	return $s.$B[($x/10^0)%10-2].$A[$x%10];
}
while(<>){
	chomp;
	my $x=$_+0;
	my $y=$x/1000000000^0;
	print txt($y).'Billion' if($y>0);
	$y=($x/1000000^0)%1000;
	print txt($y).'Million' if($y>0);
	$y=($x/1000^0)%1000;
	print txt($y).'Thousand' if($y>0);
	$y=$x%1000;
	print txt($y) if($y>0);
	print "Dollars\n";
}