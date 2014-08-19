#!/usr/bin/perl
use strict;
use warnings;
while(<>){
	chomp;
	my ($s,$t)=split(';');
	my @a=split(',',$t);
	for(my $i=0;$i<=$#a/2;$i++){$s=~s/$a[$i*2]/chr($i+65)/eg;}
	for(my $i=0;$i<=$#a/2;$i++){my $x=chr($i+65);$s=~s/$x/$a[$i*2+1]/eg;}
	print $s."\n";
}