#!/usr/bin/perl
# http://qiita.com/Nabetani/items/23ebddb44f0234e7fb15
# http://nabetani.sakura.ne.jp/hena/ord28spirwa/

use strict;
use warnings;
use feature 'say';
use IO::Handle;
STDOUT->autoflush(1);

my $dir="ESWN";
while(<>){
	my($n,$e,$s,$w,$days)=$_=~/^(\d+),(\d+),(\d+),(\d+):(\d+)$/;
	$days+=1;
	my @l=($e,$s,$w,$n);
	my $f=1;
	for(my $i=0;$f;$i++){
		my @x=($l[$i%4]+($i%4==0),($i/4<<1)+2,$l[$i%4]-($i%4==3));
		for(my $j=0;$j<3;$j++){
			if($days-$x[$j]<0){
				say substr($dir,($i+$j)%4,1);
				$f=0;
				last;
			}
			$days-=$x[$j];
		}
	}
}