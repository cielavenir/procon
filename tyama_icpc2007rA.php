#!/usr/bin/php
<?php
for(;;){
	list($n,$k,$m)=split(" ",fgets(STDIN));
	if(!$n)break;
	for($r=$i=0;++$i<$n;$r%=$i)$r+=$k;
	echo (($r+$m)%$n+1).PHP_EOL;
}
?>