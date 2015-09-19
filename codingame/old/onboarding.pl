#!/usr/bin/perl
use strict;
use warnings;
use feature 'say';
select(STDOUT); $| = 1;
for(;;){
	my $n=<>;
	my $mi=9999999;
	my $name='';
	for(my $i=0;$i<$n;$i++){
		my($enemy,$dist)=split(' ',<>);
		if($mi>$dist){
			$mi=$dist;
			$name=$enemy;
		}
	}
	say $name;
}