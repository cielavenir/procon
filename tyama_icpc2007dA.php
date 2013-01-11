#!/usr/bin/php
<?php

function judge($n){
  $ma=0;
  $mi=1000;
  $s=0;
  for($i=0;$i<$n;$i++){
    $x=fgets(STDIN)+0;
    if($x<$mi){$mi=$x;}
    if($x>$ma){$ma=$x;}
    $s+=$x;
  }
  echo floor(($s-$ma-$mi)/($n-2)),"\n";
}

while(1){
  $n=fgets(STDIN);
  if($n==0){break;}
  judge($n);
}
?>