#!/usr/bin/coffee
stdin = process.openStdin()
stdin.setEncoding 'utf8'

a=[]

stdin.on 'data', (input) ->
	x=input.split("\n")
	if x.length>2 || x[1]!='' then a=x else a.push(x[0])

stdin.on 'end', (z) ->
	n=parseInt(a.shift())
	console.log(n)
	for i in [0...n]
		b=(parseInt(e) for e in a[i].split(" "))
		y=b[0]-1
		m=b[1]-1
		r=0
		if y%3!=2 then r=Math.floor(m/2)
		console.log(196471-y*195-Math.floor(y/3)*5-m*20+r-b[2])