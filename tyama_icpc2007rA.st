#!/usr/bin/gst
n:=stdin nextLine asInteger.
[n==0]whileFalse:[
	a:=stdin nextLine subStrings:$ .
	n:=(a at:1) asInteger.
	k:=(a at:2) asInteger.
	m:=(a at:3) asInteger.
	r:=0
	1 to:(n-1) do:[:i|
		r:=(r+k)\\i.
	].
	((r+m)\\n+1) printNl.
].