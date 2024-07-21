#!/usr/bin/perl
use strict;

sub permute(&@){
	my $code = shift;
	my @a = sort {$a <=> $b} @_;
	for(;;){
		$code->(\@a);
		my $i;
		#push(@a,reverse splice @a, $n);
		for($i=$#a-1;$i>=0;$i--){if($a[$i]<$a[$i+1]){last;}}
		if($i<0){return;}
		my $k=$i;
		for($i=$#a;$i>=$k+1;$i--){if($a[$k]<$a[$i]){last;}}
		my $l=$i;
		@a[$k,$l]=@a[$l,$k];
		push(@a, reverse splice @a, $k+1);
	}
}

<>=~$";
my $n=$`;
my $k=$';
my $s_=<>;
chomp($s_);
my @s=map {ord} split('',$s_);
my $r=0;
permute {
	my $i=$n-$k;
	for(;$i>=0;$i--){
		my $x=$i;
		my $y=$i+$k-1;
		for(;$x<$y;$x++,$y--){
			last if($_[0]->[$x]!=$_[0]->[$y]);
		}
		last if $x>=$y;
	}
	$r++ if($i<0);
} @s;
print $r."\n";
