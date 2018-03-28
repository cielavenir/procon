#!/usr/bin/perl
$s=<>;
for(;$i<3;$i++){$r+=substr($s,$i,1) eq '1'}
print$r
