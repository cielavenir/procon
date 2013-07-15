#!/usr/bin/perl
use strict;
use warnings;
use feature 'say';
my $n=<>;
for(my $i=0;$i<$n;$i++){
	my($y,$m,$d)=split(/ /,<>);
	$y-=1;$m-=1;
	say 196471-$y*195-int($y/3)*5-$m*20+($y%3!=2?int($m/2):0)-$d;
}