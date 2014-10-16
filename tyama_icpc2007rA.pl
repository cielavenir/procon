#!/usr/bin/perl
use strict;
use warnings;
use feature 'say';
my($n,$k,$m,$r,$i);
for(;;say(($r+$m)%$n+1)){
	($n,$k,$m)=split(/ /,<>);
	last if(!$n);
	for($r=$i=0;++$i<$n;$r%=$i){$r+=$k}
}