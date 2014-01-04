#!/usr/bin/perl6
sub judge($n){
  my ($ma,$mi,$s)=(0,1000,0);
  loop (my $i=0;$i < $n;$i++) {
    my $x=get();
    if $x < $mi {$mi=$x;}
    if $x > $ma {$ma=$x;}
    $s=$s+$x;
  }
  say floor(($s-$ma-$mi)/($n-2));
}

loop {
  my $n=get();
  if $n==0 {last;}
  judge($n);
}