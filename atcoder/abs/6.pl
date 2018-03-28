#!/usr/bin/perl
$n=<>;
@a=sort {$b<=>$a} glob<>;
$t=1;
for($i=0;$i<$n;$i++){
	$r+=$t*$a[$i];
	$t=-$t
}
print$r
