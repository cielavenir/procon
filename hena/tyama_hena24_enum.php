#!/usr/bin/env php
<?php
//http://qiita.com/Nabetani/items/1c83005a854d2c6cbb69
//http://nabetani.sakura.ne.jp/hena/ord24eliseq/

//function cbrt($n){
//	return pow($n,1-2.0/3);
//}

function isqrt($n){
	if($n<=0)return 0;
	if($n<4)return 1;
	$x=0;$y=$n;
	for(;$x!=$y&&$x+1!=$y;){$x=$y;$y=intval((intval($n/$y)+$y)/2);}
	return $x;
}
function icbrt($n){
	if($n<0)return icbrt(-$n);
	if($n==0)return 0;
	if($n<8)return 1;
	$x=0;$y=$n;
	for(;$x!=$y&&$x+1!=$y;){$x=$y;$y=intval( (intval(intval($n/$y)/$y)+$y*2)/3 );}
	return $x;
}

function generate(){
	$i=1;
	for(;;){
		yield $i;
		$i++;
	}
}

function drop_prev($check,$prev){
	$prev->rewind();
	$a=$prev->current();
	$prev->next();
	$b=$prev->current();
	for(;;){
		if(!$check($b))yield $a;
		$a=$b;
		$prev->next();
		$b=$prev->current();
	}
}
function drop_next($check,$prev){
	$prev->rewind();
	$a=$prev->current();
	$prev->next();
	$b=$prev->current();
	yield $a;
	for(;;){
		if(!$check($a))yield $b;
		$a=$b;
		$prev->next();
		$b=$prev->current();
	}
}
function drop_n($check,$n,$prev){
	$prev->rewind();
	$i=0;
	for(;;){
		$i+=1;
		$a=$prev->current();
		$prev->next();
		if(!$check($i,$n))yield $a;
	}
}
function is_sq($n){
	//$x=intval(sqrt($n));
	$x=isqrt($n);
	return $x*$x==$n;
}
function is_cb($n){
	//$x=intval(cbrt($n));
	$x=icbrt($n);
	return $x*$x*$x==$n;
}
function is_multiple($i,$n){
	return $i%$n==0;
}
function is_le($i,$n){
	return $i<=$n;
}

$f=[
	'S'=>function($enum){return drop_next('is_sq',$enum);},
	's'=>function($enum){return drop_prev('is_sq',$enum);},
	'C'=>function($enum){return drop_next('is_cb',$enum);},
	'c'=>function($enum){return drop_prev('is_cb',$enum);},
	'h'=>function($enum){return drop_n('is_le',100,$enum);},
];
for($i=2;$i<=9;$i++){$f[(string)$i]=function($enum)use($i){return drop_n('is_multiple',$i,$enum);};}

for(;$line=fgets(STDIN);){
	//cS => $f['S']($f['c'](generate()))
	$z=array_reduce(str_split(rtrim($line)),function($s,$e)use($f){return $f[$e]($s);},generate());
	$z->rewind();
	$cnt=10;
	$a=[];
	for($i=0;$i<$cnt;$i++){
		$a[]=$z->current();
		if($i<$cnt-1)$z->next();
	}
	echo implode(',',$a).PHP_EOL;
	flush(); //STDOUT);
}
