#!/usr/bin/perl
use strict;
use warnings;
use feature 'say';
while(my $line=<>){
	chomp($line);
	my($a,$b)=split(' ',$line);
	$a=~s/0/A+/g;
	$a=~s/1/(A+|B+)/g;
	say $b=~/^$a$/ ? 'Yes' : 'No';
}