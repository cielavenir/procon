#!/usr/bin/perl
use strict;
use warnings;
sub url_decode{
	my $str = shift;
	$str =~ tr/+/ /;
	$str =~ s/%([0-9A-Fa-f][0-9A-Fa-f])/pack('H2', $1)/eg;
	return $str;
}
while(<>){
	chomp;
	my ($a,$b)=map {url_decode($_).'/'} split(';');
	$a=~/^(.*?):\/\/(.*?)\/(.*)$/;
	my @c=($1,$2,$3);
	$b=~/^(.*?):\/\/(.*?)\/(.*)$/;
	my @d=($1,$2,$3);
	$c[1].=':80' if(index($c[1],':')<0);
	$d[1].=':80' if(index($d[1],':')<0);
	$c[1].='80' if(index($c[1],':')==length($c[1])-1);
	$d[1].='80' if(index($d[1],':')==length($d[1])-1);
	print lc($c[0]) eq lc($d[0]) && lc($c[1]) eq lc($d[1]) && $c[2] eq $d[2] ? "True\n" : "False\n";
}