#!/usr/bin/coffee
stdin = process.openStdin()
stdin.setEncoding 'utf8'

n=0;s=0;ma=0;mi=1000
a=[]

input_fragment=''
stdin.on 'data', (input) ->
		ref=(input_fragment+input).split("\n")
		input_fragment=ref.pop()
		for i in [0...ref.length]
			if ref[i]==''
				continue
			a.push(ref[i]^0)

stdin.on 'end', (z) ->
	if input_fragment
		ref=(input_fragment+"\n").split("\n")
		input_fragment=ref.pop()
		for i in [0...ref.length]
			if ref[i]==''
				continue
			a.push(ref[i]^0)
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