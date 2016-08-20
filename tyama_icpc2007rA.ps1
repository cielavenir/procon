#!/usr/bin/env powershell -NonInteractive -NoProfile -File
$a=@($input)
$z=0
while(1){
	$x=$a[$z++].split()
	$n=[int]$x[0]
	$k=[int]$x[1]
	$m=[int]$x[2]
	if($n -eq 0){break}
	$r=0
	for($i=1;$i -lt $n;$i++){
		$r=($r+$k)%$i
	}
	Write-Host(($r+$m)%$n+1)
}