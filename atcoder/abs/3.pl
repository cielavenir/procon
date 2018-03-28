#!/usr/bin/perl
$r=<><<29;
for(glob<>){
	$r0=0;
	for(;$_%2<1;$_=int($_/2)){$r0++}
	if($r>$r0){$r=$r0}
}
print$r
