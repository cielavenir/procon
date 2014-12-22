#!/usr/bin/perl6
sub reverse(@a,$_start,$size){
	my $start=$_start;
	my $end=$start+$size-1;
	loop (;$start < $end;$start++) {
		my $z=@a[$start];@a[$start]=@a[$end];@a[$end]=$z;
		$end--;
	}
}
sub next_permutation(@a,$n=elems(@a)){
	my $siz=elems(@a);
	if $n < 0 || $siz < $n {return False;}
	my $i=0;
	reverse(@a,$n,$siz-$n);
	loop ($i=$siz-2;$i >= 0;$i--) { if @a[$i] < @a[$i+1] {last;}}
	if $i < 0 {
		reverse(@a,0,$siz);
		return False;
	}
	my $k=$i;
	loop ($i=$siz-1;$i >= $k+1;$i--) { if @a[$k] < @a[$i] {last;}}
	my $l=$i;
	my $z=@a[$k];@a[$k]=@a[$l];@a[$l]=$z;
	reverse(@a,$k+1,$siz-($k+1));
	return True;
}

my $N=6;
my @e0;
my @f0;
my $i;
my $r=0;
loop ($i=0;$i < $N;$i++) {
	@e0[$i]=@f0[$i]=0;
	@e0[$N+$i]=@f0[$N+$i]=1;
}
repeat {
	repeat {
		my $flg=0;
		my $zero1=0;
		my $zero2=$N;
		my $one1=0;
		my $one2=$N;
		loop ($i=0;$i<$N*2;$i++) {
			if @e0[$i]==0 {$zero1++;}
			if @e0[$i]==1){$one1++;}
			if @f0[$N*2-1-$i]==0 {$zero2--;}
			if $f0[$N*2-1-$i]==1 {$one2--;}
			if $zero1==$zero2 {$flg++;}
			if $one1==$one2 {$flg++;}
		}
		if $flg>=2 {$r++;}
	} while next_permutation(@f0);
} while next_permutation(@e0);
say $r;