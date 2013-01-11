#!/usr/bin/coffee
stdin = process.openStdin()
stdin.setEncoding 'utf8'

n=0;s=0;ma=0;mi=1000
a=[]

stdin.on 'data', (input) ->
	x=(parseInt(e) for e in input.split("\n"))
	if x.length>2 || !isNaN(x[1]) then a=x else a.push(x[0]) # x might be [num,'']

stdin.on 'end', (z) ->
	n=0
	while true
		m=a[n]
		if m==0 then process.exit()
		s=0
		ma=0
		mi=1000
		for i in [n+1..n+m]
			s=s+a[i]
			if ma<a[i] then ma=a[i]
			if mi>a[i] then mi=a[i]
		console.log Math.floor((s-ma-mi)/(m-2))
		n=n+m+1