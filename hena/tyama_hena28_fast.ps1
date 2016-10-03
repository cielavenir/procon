#!/usr/bin/env powershell
#http://qiita.com/Nabetani/items/23ebddb44f0234e7fb15
#http://nabetani.sakura.ne.jp/hena/ord28spirwa/

$dir="ESWN"
while(1){
	$line=[Console]::ReadLine()
	if($line.length -eq 0){break}
	$a=$line.Split(":")
	$b=$a[0].Split(",")
	$n=[Convert]::ToInt32($b[0])
	$e=[Convert]::ToInt32($b[1])
	$s=[Convert]::ToInt32($b[2])
	$w=[Convert]::ToInt32($b[3])
	$days=[Convert]::ToInt64($a[1])
	$days+=1
	[int[]]$l=@($e,$s,$w,$n)
	$i=0
	$f=1
	for(;$f;$i++){
		[int[]]$x=@( # それぞれ括弧でくくらないとだめっぽい
			($l[$i%4]+($i%4 -eq 0)),
			(([Math]::Floor($i/4)+1)*2),
			($l[$i%4]-($i%4 -eq 3))
		)
		for($j=0;$j -lt 3;$j++){
			if($days-$x[$j] -lt 0){
				[Console]::WriteLine($dir[($i+$j)%4])
				$f=0
				break
			}
			$days-=$x[$j]
		}
	}
	[Console]::Out.Flush()
}
