#!/usr/bin/php
<?php
$s='';
for(;;){
	$stdin=trim(fgets(STDIN));
	if(!$stdin)break;
	$s.=$stdin;
}
for($i=0;$i<39;$i++)$s=openssl_decrypt($s,'bf-cbc','bf-cbc');
echo $s;