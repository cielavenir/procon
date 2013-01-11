#!/usr/bin/php
<?php
$n=fgets(STDIN)+0;
for($i=0;$i<$n;$i++){
	list($y,$m,$d)=split(" ",fgets(STDIN));
	$y-=1;$m-=1;
	echo 196471-$y*195-floor($y/3)*5-$m*20+($y%3!=2?floor($m/2):0)-$d,"\n";
}
?>