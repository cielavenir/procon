#!/usr/bin/perl
use strict;
use warnings;
use feature 'say';
select(STDOUT); $| = 1;
for(;;){
	chomp(my $enemy_1 = <>); # name of enemy 1
	chomp(my $dist_1 = <>); # distance to enemy 1
	chomp(my $enemy_2 = <>); # name of enemy 2
	chomp(my $dist_2 = <>); # distance to enemy 2
	say($dist_1<$dist_2 ? $enemy_1 : $enemy_2);
}