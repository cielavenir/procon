#!/usr/bin/php
<?php
$n=fgets(STDIN);
for($i=0;$i<$n;$i++){
	list($a,$b,$c)=explode(' ',fgets(STDIN));
	if($a==0){
		if($b==0){printf($c!=0 ? "0\n" : "3\n");}
		else{printf("1 %.12f\n",-$c/$b);}
	}else{
		if($a<0){
			$a = -$a;
			$b = -$b;
			$c = -$c;
		}
		$d=$b*$b-4.0*$a*$c;
		if(abs($d)<1e-9){printf("1 %.12f\n",-$b/2/$a);}
		elseif($d<0){printf("0\n");}
		else{
			// acknowledgement: http://tricky.contest.atcoder.jp/submissions/120839
			$x=0;
			$y=0;
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
