<?php
$l=-3;
$r=3;
$m=0;
for($i=0;$i<10;$i++){
    $m=($l+$r)/2.0;
    $fl=f($l);
    $fr=f($r);
    $fm=f($m);
    if(abs($fl-$fm)<abs($fm-$fr))$r=$m;
    else $l=$m;
}
$y=f($m);
?>