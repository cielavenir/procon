<?php
$n=0;
$N=$M=6;
function rec($x,$y){
    global $a,$N,$M;
	if(0<=$x&&$x<$N&&0<=$y&&$y<$M&&$a[$y][$x]){
		$a[$y][$x]=0;rec($x-1,$y);rec($x+1,$y);rec($x,$y-1);rec($x,$y+1);
	}
}
for($i=0;$i<$M;$i++)for($j=0;$j<$N;$j++)if($a[$i][$j]){$n++;rec($j,$i);}
?>