#!/usr/bin/php
<?php
while(1){
	fscanf(STDIN,"%d",$n);
	$mi=9999999;
	$name='';
	for($i=0;$i<$n;$i++){
		fscanf(STDIN,"%s%f",$enemy,$dist);
		if($mi>$dist){
			$mi=$dist;
			$name=$enemy;
		}
	}
	echo $name.PHP_EOL;
}