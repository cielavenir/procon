#!/usr/bin/php
<?php
for(;;){
	fscanf(STDIN,"%s",$enemy1);
	fscanf(STDIN,"%d",$dist1);
	fscanf(STDIN,"%s",$enemy2);
	fscanf(STDIN,"%d",$dist2);
	echo ($dist1<$dist2 ? $enemy1 : $enemy2).PHP_EOL;
}