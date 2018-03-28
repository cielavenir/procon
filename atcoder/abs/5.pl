#!/usr/bin/perl
<>=~/ (.+) /;
for($i=1;$i<=$`;$i++){
	$s=0;
	$j=$i;
	for(;$j;$j=int($j/10)){$s+=$j%10}
	if($1<=$s&&$s<=$'){$r+=$i}
}
print$r
