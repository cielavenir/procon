#!/usr/bin/env powershell
while(1){
	[int]$n=[Console]::ReadLine()
	if($n -eq 0){break}
	$mi=1000;$ma=0;$sum=0;
	for($i=0;$i -lt $n;$i++){
		[int]$x=[Console]::ReadLine()
		if($mi -gt $x){$mi=$x}
		if($ma -lt $x){$ma=$x}
		$sum+=$x
	}
	Write-Host([math]::Truncate(($sum-$mi-$ma)/($n-2)))
}