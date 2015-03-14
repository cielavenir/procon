<?php
/*
//言い訳：可変長引数対応にするとTLEになるので諦めた.
function fast_array_intersect(){
	$args=func_get_args();
	$a=$args[0];
	$vec=range(0,count($a)-1);
	for($idx=1;$idx<count($args);$idx++){
		$la=count($a);
		$lb=count($args[$idx]);
		$c=array();
		$newvec=array();
		for($ia=$ib=0;;){
		if(FALSE){
			for(;$ia<$la&&$a[$vec[$ia]]<$args[$idx][$ib];)$ia++;
			if($ia>=$la)break;
			for(;$ib<$lb&&$a[$vec[$ia]]>$args[$idx][$ib];)$ib++;
			if($ib>=$lb)break;
			if($a[$vec[$ia]]==$args[$idx][$ib]){
				$c[$vec[$ia]]=$a[$vec[$ia]];
				$newvec[]=$ia;
				$ia++;$ib++;
				if($ia>=$la||$ib>=$lb)break;
			}
		}else{
			for(;$ia<$la&&$a[$ia]<$args[$idx][$ib];)$ia++;
			if($ia>=$la)break;
			for(;$ib<$lb&&$a[$ia]>$args[$idx][$ib];)$ib++;
			if($ib>=$lb)break;
			if($a[$ia]==$args[$idx][$ib]){
				$c[]=$a[$ia];
				$newvec[]=$vec[$ia];
				$ia++;$ib++;
				if($ia>=$la||$ib>=$lb)break;
			}
		}
		}
		$a=$c;
		$vec=$newvec;
	}
	$r=array();
	$la=count($a);
	for($i=0;$i<$la;$i++)$r[$vec[$i]]=$a[$i];
	return $r;
	//return $a;
}
*/
function fast_array_intersect($a,$b,$c){
	$la=count($a);
	$lb=count($b);
	$lc=count($c);
	$r=array();
	for($ia=$ib=$ic=0;;){
		for(;$ia<$la&&($a[$ia]<$b[$ib] || $a[$ia]<$c[$ic]);)$ia++;
		if($ia>=$la)break;
		for(;$ib<$lb&&$a[$ia]>$b[$ib];)$ib++;
		if($ib>=$lb)break;
		for(;$ic<$lc&&$a[$ia]>$c[$ic];)$ic++;
		if($ic>=$lc)break;
		if($a[$ia]==$b[$ib] && $a[$ia]==$c[$ic]){
			$r[$ia]=$a[$ia];
			$ia++;$ib++;$ic++;
			if($ia>=$la||$ib>=$lb||$ic>=$lc)break;
		}
	}
	return $r;
}
?>