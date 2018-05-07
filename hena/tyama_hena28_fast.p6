#!/usr/bin/env perl6
# http://qiita.com/Nabetani/items/23ebddb44f0234e7fb15
# http://nabetani.sakura.ne.jp/hena/ord28spirwa/

$*OUT.out-buffer=False;
my $dir="ESWN";
loop (;my $line=get();) {
	$line ~~ /^(\d+)","(\d+)","(\d+)","(\d+)":"(\d+)/;
	my $n=+$0;
	my $e=+$1;
	my $s=+$2;
	my $w=+$3;
	my $days=+$4+1;
	my @l=($e,$s,$w,$n);
	my $f=1;
	loop (my $i=0;$f;$i++) {
		my $j=0;
		my @x=(@l[$i%4]+($i%4==0),($i/4 +< 1)+2,@l[$i%4]-($i%4==3));
		loop ($j=0;$j < 3;$j++) {
			if ($days-@x[$j] < 0) {
				say substr($dir,($i+$j)%4,1);
				$f=0;
				last;
			}
			$days-=@x[$j];
		}
	}
	#$*OUT.flush();
}
