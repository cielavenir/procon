#!/usr/bin/perl --
use strict;
use warnings;

=pod
tyama_square.pl 070626
ACM-ICPC Japanese Alumni
2007 D Square Route
Dedicated to K.Inaba

#execution time
D1: 38.76s
D2: 38.56s
D3: 38.85s
D4: 38.60s
=cut

#time
#$t = (times)[0];

while(1){
  my @n=();
  my @m=();
  my %point=();
  $n[0]=$m[0]=0;
  my $count=0;

  my($cn, $cm) = split(" ",<>);
  if($cn eq "0"){last;}

  for(my $i=0;$i<$cn;$i++){
    $n[$i+1]=$n[$i]+<>;
  }
  for(my $i=0;$i<$cm;$i++){
    $m[$i+1]=$m[$i]+<>;
  }
  
  foreach my $_n(@n){
    foreach my $_m(@m){
	  $point{$_n-$_m}++;
	}
  }
  
  foreach my $key(keys %point){
    my $c = $point{$key};
	$count+=$c*($c-1)/2;
  }
  print $count."\n";
}

#printf("\n%.2f\n",(times)[0]-$t);
exit;