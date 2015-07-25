#!/usr/bin/gst
n:=stdin nextLine asInteger.
1 to:n do:[:i|
	a:=stdin nextLine subStrings:$ .
	y:=(a at:1) asInteger-1.
	m:=(a at:2) asInteger-1.
	d:=(a at:3) asInteger.
	x:=0
	(y\\3<2)ifTrue:[x:=m//2.].
	(196471-y*195-y/3*5-m*20+x-d) printNl.
].