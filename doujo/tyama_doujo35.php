<?php
function check_collision($rect_1, $rect_2){
$c=$rect_1['left']+$rect_1['width'];
$d=$rect_1['top'];
$a=$rect_1['left'];
$b=$rect_1['top']-$rect_1['height'];
$g=$rect_2['left']+$rect_2['width'];
$h=$rect_2['top'];
$e=$rect_2['left'];
$f=$rect_2['top']-$rect_2['height'];
return !($a>$g||$e>$c||$b>$h||$f>$d);
}
?>