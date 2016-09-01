#!/usr/bin/ruby
s=DATA.gets
314161.times{|i|p i
	s=IO.popen('php','r+b'){|io|
		io.puts s
		io.close_write
		io.read
	}
	puts s if i%1000==0
}
puts s
# <?printf($a=($b=0)?'<?printf($a=($b=%d)?%c%s%c:"%s-%s",$b-1,39,$a,39,dechex($x=%d),dechex($y=%d),$x+$x+$y,-$x);':"bf-cbc",$b-1,39,$a,39,dechex($x=3642),dechex($y=-191),$x+$x+$y,-$x);
# bf-cbc
__END__
<?printf($a='<?printf($a=($b=%d)?%c%s%c:"%s-%s",$b-1,39,$a,39,dechex($x=%d),dechex($y=%d),$x+$x+$y,-$x);',314159,39,$a,39,'','',-1084159067,1084162518);