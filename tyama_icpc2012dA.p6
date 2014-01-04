#!/usr/bin/perl6
my $n=get();
loop (my $i=0;$i < $n;$i++) {
	my ($y,$m,$d)=split(' ',get());
	$y-=1;$m-=1;
	my $r = $y%3 != 2 ?? floor($m/2) !! 0;
	say 196471-$y*195-floor($y/3)*5-$m*20+$r-$d;
}