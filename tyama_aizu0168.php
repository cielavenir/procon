#!/usr/bin/php
<?php
$a=array(1,1,2);
for($i=3;$i<31;$i++)array_push($a,$a[$i-1]+$a[$i-2]+$a[$i-3]);
for(;$n=intval(fgets(STDIN));)echo intval(($a[$n]+3649)/3650).PHP_EOL;
?>