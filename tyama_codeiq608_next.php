#!/usr/bin/php
<?php
function reverse(&$a,$start,$size){
	$end=$start+$size-1;
	for(;$start<$end;$start++){
		$z=$a[$start];$a[$start]=$a[$end];$a[$end]=$z;
		$end--;
	}
}
function next_permutation(&$a,$_n=null){
	$siz=count($a);
	$n=$_n || $siz;
	if($n<0||$siz<$n)return false;
	$i=0;
	reverse($a,$n,$siz-$n);
	for($i=$siz-2;$i>=0;$i--)if($a[$i]<$a[$i+1])break;
	if($i<0){
		reverse($a,0,$siz);
		return false;
	}
	$k=$i;
	for($i=$siz-1;$i>=$k+1;$i--)if($a[$k]<$a[$i])break;
	$l=$i;
	$z=$a[$k];$a[$k]=$a[$l];$a[$l]=$z;
	reverse($a,$k+1,$siz-($k+1));
	return true;
}

$N=6;
$e0=array_fill(0,$N*2,0);$f0=array_fill(0,$N*2,0);$i=0;$r=0;
for($i=0;$i<$N;$i++)$e0[$N+$i]=$f0[$N+$i]=1;
$e=array(0);
$f=array(0);
do{
	for($i=0;$i<$N*2;$i++)$e[$i+1]=$e[$i]+$e0[$i];
	do{
		for($i=0;$i<$N*2;$i++){
			$f[$i+1]=$f[$i]+$f0[$i];
			if($e[$i]==$f[$i]&&$e[$i+1]==$f[$i+1])break;
		}
		if($i==$N*2)$r++;
	}while(next_permutation($f0));
}while(next_permutation($e0));
echo $r.PHP_EOL;
?>