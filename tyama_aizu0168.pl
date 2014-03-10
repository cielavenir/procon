#!/usr/bin/perl
use strict;
use warnings;
my @a=(1,1,2);
for(my $i=3;$i<31;$i++){push(@a,$a[$i-1]+$a[$i-2]+$a[$i-3]);}
for(;my $n=int(<>);){print int(($a[$n]+3649)/3650)."\n";}