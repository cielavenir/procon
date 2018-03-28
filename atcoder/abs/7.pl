#!/usr/bin/perl
$n=<>;
$h{$_}=1 for<>;
print scalar keys %h;
