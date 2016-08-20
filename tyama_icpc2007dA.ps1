#!/usr/bin/env powershell -NonInteractive -NoProfile -File
$a=@($input)
$z=0
while(1){
	[int]$n=$a[$z++]
	if($n -eq 0){break}
	$mi=1000;$ma=0;$sum=0;
	for($i=0;$i -lt $n;$i++){
		[int]$x=$a[$z++]
		if($mi -gt $x){$mi=$x}
		if($ma -lt $x){$ma=$x}
		$sum+=$x
	}
	Write-Host([math]::Truncate(($sum-$mi-$ma)/($n-2)))
}