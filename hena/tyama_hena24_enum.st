#!/usr/bin/env gst

isqrt := [:n |
	|x y|
	(n<=0)ifTrue:[0.]ifFalse:[
		(n<4)ifTrue:[1.]ifFalse:[
			x:=0.
			y:=n.
			[x~~y and: [x+1~~y]]whileTrue:[
				x:=y.
				y:=(n//y+y)//2.
			].
			x.
		].
	].
].

icbrt := [:n |
	|x y|
	(n<0)ifTrue:[0-(icbrt value: 0-n).]ifFalse:[
		(n==0)ifTrue:[0.]ifFalse:[
			(n<8)ifTrue:[1.]ifFalse:[
				x:=0.
				y:=n.
				[x~~y and: [x+1~~y]]whileTrue:[
					x:=y.
					y:=(n//y//y+y+y)//3. "somehow n//y//y+y*2 does not work"
				].
				x.
			].
		].
	].
].

generate := [
	Generator on:[:y|
		i:=1.
		[true]whileTrue:[
			y yield: i.
			i:=i+1.
		].
	].
].

drop_prev := [:check :prev|
	Generator on:[:y|
		|a b|
		a:=prev next.
		b:=prev next.
		[true]whileTrue:[
			(check value: b)ifFalse:[y yield: a].
			a:=b.
			b:=prev next.
		].
	].
].

drop_next := [:check :prev|
	Generator on:[:y|
		|a b|
		a:=prev next.
		b:=prev next.
		y yield: a.
		[true]whileTrue:[
			(check value: a)ifFalse:[y yield: b].
			a:=b.
			b:=prev next.
		].
	].
].

drop_n := [:check :n :prev|
	Generator on:[:y|
		|i a|
		i:=0.
		[true]whileTrue:[
			i:=i+1.
			a:=prev next.
			(check value: i value: n)ifFalse:[y yield: a].
		].
	].
].

is_sq := [:n|
	|x|
	x:=isqrt value: n.
	x*x==n.
].
is_cb := [:n|
	|x|
	x:=icbrt value: n.
	x*x*x==n.
].
is_multiple := [:i :n|
	i\\n==0.
].
is_le := [:i :n|
	i<=n.
].

main := [:input|
	|f|
	f := Dictionary new.
	f at: 'S' put: [:e|drop_next value: is_sq value: e.].
	f at: 's' put: [:e|drop_prev value: is_sq value: e.].
	f at: 'C' put: [:e|drop_next value: is_cb value: e.].
	f at: 'c' put: [:e|drop_prev value: is_cb value: e.].
	f at: 'h' put: [:e|drop_n value: is_le value: 100 value: e.].
	f at: '2' put: [:e|drop_n value: is_multiple value: 2 value: e.].
	f at: '3' put: [:e|drop_n value: is_multiple value: 3 value: e.].
	f at: '4' put: [:e|drop_n value: is_multiple value: 4 value: e.].
	f at: '5' put: [:e|drop_n value: is_multiple value: 5 value: e.].
	f at: '6' put: [:e|drop_n value: is_multiple value: 6 value: e.].
	f at: '7' put: [:e|drop_n value: is_multiple value: 7 value: e.].
	f at: '8' put: [:e|drop_n value: is_multiple value: 8 value: e.].
	f at: '9' put: [:e|drop_n value: is_multiple value: 9 value: e.].

	[input atEnd]whileFalse:[
		|i c line stream|
		line := input nextLine.
		stream := generate value.
		1 to: line size do:[:index|
			c := (line at: index) asString.
			stream := (f at: c) value: stream.
		].
		i:=0.
		[i<10]whileTrue:[
			(i>0)ifTrue:[',' displayOn: stdout.].
			stream next displayOn: stdout.
			i:=i+1.
		].
		Character nl displayOn: stdout.
		stdout flush.
	].
].
main value: stdin.
