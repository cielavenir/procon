#!/usr/bin/perl
<>=~$";
for($i=0;$i<=$`;$i++){
	for($j=0;$j<=$`-$i;$j++){
		$k=$`-$i-$j;
		if($i*1000+$j*5000+$k*10000==$'){
			printf("%d %d %d",$k,$j,$i);
			exit
		}
	}
}
print"-1 -1 -1"
