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
	a.pop()
	for _i in [0...a.length]
		b=(parseInt(e) for e in a[_i].split(" "))
		n=b[0]
		k=b[1]
		m=b[2]
		r=i=0
		while ++i<n
			r=(r+k)%i
		console.log((r+m)%n+1)