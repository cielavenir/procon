#!/usr/bin/php
<?php
// http://qiita.com/Nabetani/items/23ebddb44f0234e7fb15
// http://nabetani.sakura.ne.jp/hena/ord28spirwa/

$dir="ESWN";
$n=0;$e=0;$s=0;$w=0;
$days=0;
for(;fscanf(STDIN,"%d,%d,%d,%d:%d",$n,$e,$s,$w,$days)==5;){
	$days+=1;
	$l=array($e,$s,$w,$n);
	$f=1;
	for($i=0;$f;$i++){
		$x=array($l[$i%4]+($i%4==0),($i/4<<1)+2,$l[$i%4]-($i%4==3));
		for($j=0;$j<3;$j++){
			if($days-$x[$j]<0){
				echo $dir[($i+$j)%4].PHP_EOL;
				$f=0;
				break;
			}
			$days-=$x[$j];
		}
	}
	fflush(STDOUT);
}