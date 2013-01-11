#!/usr/bin/perl
use strict;
use warnings;
my $x=<>;my $s=<>;
eval "\$s=~tr/$x//d";
print $s."\n";