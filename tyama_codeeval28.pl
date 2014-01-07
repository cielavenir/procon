#!/usr/bin/perl
use strict;
use warnings;
use feature 'say';
while(<>){
	chomp;
	my ($a,$b)=split(',');
	$b=~s/\\\*/+/g;
	$b=~s/\*/.*/g;
	$b=~s/\+/\\*/g;
	say $a=~/$b/ ? 'true' : 'false';
}