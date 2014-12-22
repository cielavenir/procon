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
permute {
	my @_e=@_;
	permute {
		my $flg=0;
		my $zero1=0;
		my $zero2=$N;
		my $one1=0;
		my $one2=$N;
		for($i=0;$i<$N*2;$i++){
			if($_e[$i]==0){$zero1++;}
			if($_e[$i]==1){$one1++;}
			if($_[$N*2-1-$i]==0){$zero2--;}
			if($_[$N*2-1-$i]==1){$one2--;}
			if($zero1==$zero2){$flg++;}
			if($one1==$one2){$flg++;}
		}
		if($flg>=2){$r++;}
		1;
	} @f0;
	1;
} @e0;
print $r."\n";