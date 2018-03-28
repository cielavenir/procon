#!/usr/bin/perl
for($n=<>;$n--;){
	#@a=glob<>;$dt=$a[0]-$t;$dx=$a[1]-$x;$dy=$a[2]-$y;
	<>=~/ (.+) /;$dt=$`-$t;$dx=$1-$x;$dy=$'-$y;
	if($dx+$dy>$dt || ($dt-$dx-$dy)%2){
		print'No';
		exit
	}
	$t=$`;
	$x=$1;
	$y=$';
}
print'Yes'
