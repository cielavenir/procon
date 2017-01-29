#!/usr/bin/perl
use strict;
my $n=<>;
for(my $i=0;$i<$n;$i++){
	my($a,$b,$c)=split(' ',<>);
	if($a==0){
		if($b==0){printf($c!=0 ? "0\n" : "3\n");}
		else{printf("1 %.12f\n",-$c/$b);}
	}else{
		if($a<0){
			$a = -$a;
			$b = -$b;
			$c = -$c;
		}
		my $d=$b*$b-4.0*$a*$c;
		if(abs($d)<1e-9){printf("1 %.12f\n",-$b/2/$a);}
		elsif($d<0){printf("0\n");}
		else{
			# acknowledgement: http://tricky.contest.atcoder.jp/submissions/120839
			my $x=0;
			my $y=0;
			if($b>0){
				$x = (-$b-sqrt($d))/2/$a;
				$y = $c/$a/$x;
			}else{
				$y = (-$b+sqrt($d))/2/$a;
				$x = $c/$a/$y;
			}
			printf("2 %.12f %.12f\n",$x,$y);
		}
	}
}
