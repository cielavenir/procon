#!/usr/bin/env perl
#http://nabetani.sakura.ne.jp/hena/orde24tancho/
#https://qiita.com/Nabetani/items/928d6a94d83c21ef64d7

use strict;
use warnings;
use IO::Handle;
STDOUT->autoflush(1);

sub comb{
	my($n,$k)=@_;
	my $r=1;
	for(my $i=0;$i<$k;$i++){
		$r=$r*($n-$i)/($i+1)
	}
	return $r
}

while(<>){
	my($b,$n)=split(',',$_);
	$b--;
	$n--;
	my $topdigit=1;
	for(;;){
		my $x=comb($b,$topdigit);
		last if($b<$topdigit || $x>$n);
		$n-=$x;
		$topdigit++
	}
	if($b<$topdigit){
		print "-\n";
		next
	}
	$topdigit--;
	my $curnumber=0;
	for(my $d=$topdigit;$d>=0;$d--){
		$curnumber++;
		for(;;){
			my $x=comb($b-$curnumber,$d);
			last if($x>$n);
			$n-=$x;
			$curnumber++
		}
		printf("%c",$curnumber+($curnumber<10 ? 48 : 87))
	}
	print("\n")
}
