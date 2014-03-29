#!/usr/bin/perl
use strict;
#use warnings;
use v5.10;
my %h=();
while(my $line=<>){
	chomp($line);
	while(1){
		#say $line;
		my $candidate;
		if($line=~/(0x[0-9a-f]+)\.(0x[0-9a-f]+)\.(0x[0-9a-f]+)\.(0x[0-9a-f]+)/){
			my $l=length($`)+length($&);
			$candidate=hex(substr($1,2)).'.'.hex(substr($2,2)).'.'.hex(substr($3,2)).'.'.hex(substr($4,2));
			$line=substr($line,$l);
		}elsif($line=~/(0x[0-9a-f]+)/){
			my $l=length($`)+length($&);
			my $x=hex(substr($1,2));
			$candidate=($x>>24).'.'.(($x>>16)&0xff).'.'.(($x>>8)&0xff).'.'.(($x>>0)&0xff);
			$line=substr($line,$l);
		}elsif($line=~/(1[01]*)\.([01]+)\.([01]+)\.([01]+)/){
			my $l=length($`)+length($&);
			$candidate=hex(unpack('H*',pack('B*',$1))).'.'.hex(unpack('H*',pack('B*',$2))).'.'.hex(unpack('H*',pack('B*',$3))).'.'.hex(unpack('H*',pack('B*',$4)));
			$line=substr($line,$l);
		}elsif($line=~/([01]{9,})/){
			my $l=length($`)+length($&);
			my $x=hex(unpack('H*',pack('B*',$1)));
			$candidate=($x>>24).'.'.(($x>>16)&0xff).'.'.(($x>>8)&0xff).'.'.(($x>>0)&0xff);
			$line=substr($line,$l);
		}elsif($line=~/(0[0-9]+)\.(0[0-9]+)\.(0[0-9]+)\.(0[0-9]+)/){
			my $l=length($`)+length($&);
			$candidate=oct(substr($1,1)).'.'.oct(substr($2,1)).'.'.oct(substr($3,1)).'.'.oct(substr($4,1));
			$line=substr($line,$l);
		}elsif($line=~/(0[0-9]+)/){
			my $l=length($`)+length($&);
			my $x=oct(substr($1,1));
			$candidate=($x>>24).'.'.(($x>>16)&0xff).'.'.(($x>>8)&0xff).'.'.(($x>>0)&0xff);
			$line=substr($line,$l);
		}elsif($line=~/([0-9]+)\.([0-9]+)\.([0-9]+)\.([0-9]+)/){
			my $l=length($`)+length($&);
			$candidate=(substr($1,0)).'.'.(substr($2,0)).'.'.(substr($3,0)).'.'.(substr($4,0));
			$line=substr($line,$l);
		}elsif($line=~/([0-9]+)/){
			my $l=length($`)+length($&);
			my $x=(substr($1,0));
			$candidate=($x>>24).'.'.(($x>>16)&0xff).'.'.(($x>>8)&0xff).'.'.(($x>>0)&0xff);
			$line=substr($line,$l);
		}else{
			last;
		}
		#say $candidate;
		my @a=split(/\./,$candidate);
		if($a[0]<1||255<$a[0] || $a[1]<0||255<$a[1] || $a[2]<0||255<$a[2] || $a[3]<0||255<$a[3]){next;}
		$h{$candidate}++;
	}
}
say((sort {-($h{$a} <=> $h{$b})} keys %h)[0]);