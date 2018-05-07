#!/usr/bin/env perl6
#http://qiita.com/Nabetani/items/1c83005a854d2c6cbb69
#http://nabetani.sakura.ne.jp/hena/ord24eliseq/

sub isqrt($n){
	if $n <= 0 {return 0;}
	if $n < 4 {return 1;}
	my $x=0;my $y=$n;
	loop (;$x != $y && $x+1 != $y;) {$x=$y;$y=(($n div $y)+$y) div 2;}
	return $x;
}

sub icbrt($n){
	if $n < 0 {return icbrt(-$n);}
	if $n == 0 {return 0;}
	if $n < 8 {return 1;}
	my $x=0;my $y=$n;
	loop (;$x != $y && $x+1 != $y;) {$x=$y;$y=(($n div $y div $y)+$y*2) div 3;}
	return $x;
}

sub generate{
	return lazy gather {
		my $i=1;
		loop (;;) {
			take $i;
			$i++;
		}
	}
}

sub drop_prev($check,@prev){
	return lazy gather {
		my $a=@prev[0];
		my $b=@prev[1];
		my $i=2;
		loop (;;) {
			take $a if !$check($b);
			$a=$b;
			$b=@prev[$i];
			$i++;
		}
	}
}
sub drop_next($check,@prev){
	return lazy gather {
		my $a=@prev[0];
		my $b=@prev[1];
		my $i=2;
		take $a;
		loop (;;) {
			take $b if !$check($a);
			$a=$b;
			$b=@prev[$i];
			$i++;
		}
	}
}
sub drop_n($check,$n,@prev){
	return lazy gather {
		my $i=0;
		loop (;;) {
			my $a=@prev[$i];
			$i+=1;
			take $a if !$check($i,$n);
		}
	}
}
sub is_sq($n){
	#my $x=int(sqrt($n));
	my $x=isqrt($n);
	return $x*$x == $n;
}
sub is_cb($n){
	#my $x=int(cbrt($n));
	my $x=icbrt($n);
	return $x*$x*$x == $n;
}
sub is_multiple($i,$n){
	return $i%$n == 0;
}
sub is_le($i,$n){
	return $i <= $n;
}

my %f=(
	'S'=>sub (@enum) {return drop_next(&is_sq,@enum);},
	's'=>sub (@enum) {return drop_prev(&is_sq,@enum);},
	'C'=>sub (@enum) {return drop_next(&is_cb,@enum);},
	'c'=>sub (@enum) {return drop_prev(&is_cb,@enum);},
	'h'=>sub (@enum) {return drop_n(&is_le,100,@enum);},
);
loop (my $i=2;$i <= 9;$i++) {%f{"$i"}=sub ($i) {sub (@enum) {return drop_n(&is_multiple,$i,@enum);}}($i);}

$*OUT.out-buffer=False;
loop (;my $line=get();) {
	chomp($line);
	#cS => $f['S']->($f['c']->(generate()))
	my @z=reduce {%f{$^b}($^a)},generate(),|$line.split("",:skip-empty);
	my $cnt=10;
	my @a;
	loop (my $i=0;$i < $cnt;$i++) {
		push(@a,shift(@z));
	}
	say join(',',@a);
	#$*OUT.flush();
}
