<?php
function array_flatten($a){ //flattens multi-dim arrays (distroys keys)
    $ab = array(); if(!is_array($a)) return $ab;
    foreach($a as $value){
        if(is_array($value)){
            $ab = array_merge($ab,array_flatten($value));
        }else{
            array_push($ab,$value);
        }
    }
    return $ab;
}
$x=array_flatten($a);
$b = 0;
for($i=0;$i<count($x);$i++)if($x[$i]&&!$b)$b=$x[$i];
?>