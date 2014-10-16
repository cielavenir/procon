#!/usr/bin/perl6
my($n,$k,$m,$r,$i);
loop {
	($n,$k,$m)=split(' ',get());
	last if ($n==0);
	loop ($r=$i=0;++$i<$n;$r%=$i) {$r+=$k}
	say ($r+$m)%$n+1;
}