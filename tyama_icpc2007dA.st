#!/usr/bin/gst

judge:=[:n|
	ma:=0.
	mi:=1000.
	s:=0.
	1 to:n do:[:i|
		x:=stdin nextLine asInteger.
		(x<mi)ifTrue:[mi:=x].
		(x>ma)ifTrue:[ma:=x].
		s:=s+x.
	].
	((s-ma-mi)//(n-2)) printNl.
].

n:=1.
[n==0]whileFalse:[
	n:=stdin nextLine asInteger.
	(n==0)ifFalse:[judge value: n].
].