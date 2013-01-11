#!/work/misc/cmd/xlclaire-v3.5.0/Linux-unknown-g++4.6/cclaire -x0-0
// I never know what the hell 0-0 is...

sum(n:integer, ma:integer, mi:integer, s:integer, z:integer) : integer -> (
	if (n = 0) (
		(s - ma - mi) / (z - 2)
	) else (
		let x := integer!(freadline(stdin)) in sum(n - 1,max(ma,x),min(mi,x),s + x,z)
	)
)

perform(n:integer) : void -> (
	if (n = 0) (
		true
	) else (
		printf("~S\n",sum(n,0,1000,0,n)),
		perform(integer!(freadline(stdin)))
	)
)

( perform(integer!(freadline(stdin))) )