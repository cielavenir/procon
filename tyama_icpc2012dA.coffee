#!/usr/bin/coffee
stdin = process.openStdin()
stdin.setEncoding 'utf8'

a=[]

input_fragment=''
stdin.on 'data', (input) ->
		ref=(input_fragment+input).split("\n")
		input_fragment=ref.pop()
		for i in [0...ref.length]
			if ref[i]==''
				continue
			a.push(ref[i])

stdin.on 'end', (z) ->
	if input_fragment
		ref=(input_fragment+"\n").split("\n")
		input_fragment=ref.pop()
		for i in [0...ref.length]
			if ref[i]==''
				continue
			a.push(ref[i])
	n=parseInt(a.shift())
	for i in [0...n]
		b=(parseInt(e) for e in a[i].split(" "))
		y=b[0]-1
		m=b[1]-1
		r=0
		if y%3!=2 then r=Math.floor(m/2)
		console.log(196471-y*195-Math.floor(y/3)*5-m*20+r-b[2])