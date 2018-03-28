#!/usr/bin/perl
@T=map {scalar reverse $_} ("dream","dreamer","erase","eraser");
$s=<>;
chomp($s);
$s=reverse($s);
$l=length($s);
for($c=0;$c<$l;){
	$k=-1;
	for($i=0;$i<4;$i++){
		if(substr($s,$c,length($T[$i])) eq $T[$i]){
			$k=length($T[$i]);
			last;
		}
	}
	if($k<0){
		print'NO';
		exit
	}
	$c+=$k;
}
print'YES'
