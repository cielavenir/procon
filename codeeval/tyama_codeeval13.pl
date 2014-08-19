#!/usr/bin/perl
use strict;
use warnings;
while(my $line=<>){
	chomp($line);
	my($str,$rem)=split(/, /,$line);
	eval "\$str=~tr/$rem//d";
	print $str."\n";
}