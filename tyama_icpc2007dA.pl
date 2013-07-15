#!/usr/bin/perl --
use strict;
use warnings;

sub judge{
  my($n,$ma,$mi,$s)=($_[0],0,1000,0);
  for(my $i=0;$i<$n;$i++){
    my $x=<>;
    if($x<$mi){$mi=$x;}
    if($x>$ma){$ma=$x;}
    $s+=$x;
  }
  print int(($s-$ma-$mi)/($n-2));
  print "\n";
}

while(1){
  my $n=<>;
  if($n==0){last;}
  judge($n);
}