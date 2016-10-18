<?php
function fast_array_diff($a,$b,$c){
	$la=count($a);
	$lb=count($b);
	$lc=count($c);
	$r=array();
	for($ia=$ib=$ic=0;;){
		for(;$ia<$la && ($ib>=$lb||$a[$ia]<$b[$ib]) && ($ic>=$lc||$a[$ia]<$c[$ic]);){
			$r[$ia]=$a[$ia];
			$ia++;
		}
		if($ia>=$la)break;
		for(;$ib<$lb&&$a[$ia]>$b[$ib];)$ib++;
		for(;$ic<$lc&&$a[$ia]>$c[$ic];)$ic++;
		if($ib>=$lb && $ic>=$lc)break;
		$da=0;
		if($ib<$lb && $a[$ia]==$b[$ib]){
			$da=1;
			$ib++;
		}
		if($ic<$lc && $a[$ia]==$c[$ic]){
			$da=1;
			$ic++;
		}
		$ia+=$da;
	}
	return $r;
}
//print_r(fast_array_diff(array(1,2,3,4,5,6,7,8),array(1,2,5,7),array(2,3,4,5,6,7)));
//print_r(array_diff(array(1,2,3,4,5,6,7,8),array(1,2,5,7),array(2,3,4,5,6,7)));
?>