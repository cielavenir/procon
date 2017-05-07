#!/usr/bin/env perl
#http://qiita.com/Nabetani/items/1c83005a854d2c6cbb69
#http://nabetani.sakura.ne.jp/hena/ord24eliseq/

use strict vars;
use feature qw(say);
use IO::Handle;
use Generator::Object;
use List::Util qw(reduce);

#sub cbrt{
#	my($n)=@_;
#	return $n**(1-2.0/3);
#}

sub isqrt{
	my($n)=@_;
	if($n<=0){return 0;}
	if($n<4){return 1;}
	my $x=0;my $y=$n;
	for(;$x!=$y&&$x+1!=$y;){$x=$y;$y=int((int($n/$y)+$y)/2);}
	return $x;
}
sub icbrt{
	my($n)=@_;
	if($n<0){return icbrt(-$n);}
	if($n==0){return 0;}
	if($n<8){return 1;}
	my $x=0;my $y=$n;
	for(;$x!=$y&&$x+1!=$y;){$x=$y;$y=int( (int(int($n/$y)/$y)+$y*2)/3 );}
	return $x;
}

sub generate{
	generator{
		my $i=1;
		for(;;){
			$_->yield($i);
			$i++;
		}
	}
}

sub drop_prev{
	my($check,$prev)=@_;
	generator{
		my $a=$prev->next;
		my $b=$prev->next;
		for(;;){
			$_->yield($a) if !$check->($b);
			$a=$b;
			$b=$prev->next;
		}
	}
}
sub drop_next{
	my($check,$prev)=@_;
	generator{
		my $a=$prev->next;
		my $b=$prev->next;
		$_->yield($a);
		for(;;){
			$_->yield($b) if !$check->($a);
			$a=$b;
			$b=$prev->next;
		}
	}
}
sub drop_n{
	my($check,$n,$prev)=@_;
	generator{
		my $i=0;
		for(;;){
			$i+=1;
			$a=$prev->next;
			$_->yield($a) if !$check->($i,$n);
		}
	}
}
sub is_sq{
	my($n)=@_;
	#my $x=int(sqrt($n));
	my $x=isqrt($n);
	return $x*$x==$n;
}
sub is_cb{
	my($n)=@_;
	#my $x=int(cbrt($n));
	my $x=icbrt($n);
	return $x*$x*$x==$n;
}
sub is_multiple{
	my($i,$n)=@_;
	return $i%$n==0;
}
sub is_le{
	my($i,$n)=@_;
	return $i<=$n;
}

my %f=(
	'S'=>sub{my($enum)=@_;return drop_next('is_sq',$enum);},
	's'=>sub{my($enum)=@_;return drop_prev('is_sq',$enum);},
	'C'=>sub{my($enum)=@_;return drop_next('is_cb',$enum);},
	'c'=>sub{my($enum)=@_;return drop_prev('is_cb',$enum);},
	'h'=>sub{my($enum)=@_;return drop_n('is_le',100,$enum);},
);
for(my $i=2;$i<=9;$i++){$f{"$i"}=sub{my($i)=@_;sub{my($enum)=@_;return drop_n('is_multiple',$i,$enum);}}->($i);}

STDOUT->autoflush;
for(;my $line=<>;){
	chomp($line);
	#cS => $f['S']->($f['c']->(generate()))
	my $z=reduce {$f{$b}->($a)} generate(),split('',$line);
	my $cnt=10;
	my @a;
	for(my $i=0;$i<$cnt;$i++){
		push(@a,$z->next);
	}
	say join(',',@a);
}
