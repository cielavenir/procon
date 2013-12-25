#!/usr/bin/perl
use strict;
sub permute(&@){
	my $code = shift;
	my @a = @_;
	while($code->(@a)){
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

my $N=6;
my @e0;
my @f0;
my $i;
my $r=0;
for($i=0;$i<$N;$i++){$e0[$i]=$f0[$i]=0;}
for($i=0;$i<$N;$i++){$e0[$N+$i]=$f0[$N+$i]=1;}
my @e=(0);
my @f=(0);
permute {
	for($i=0;$i<$N*2;$i++){$e[$i+1]=$e[$i]+$_[$i];}
	permute {
		for($i=0;$i<$N*2;$i++){
			$f[$i+1]=$f[$i]+$_[$i];
			if($e[$i]==$f[$i]&&$e[$i+1]==$f[$i+1]){last;}
		}
		if($i==$N*2){$r++;}
		1;
	} @f0;
	1;
} @e0;
print $r."\n";